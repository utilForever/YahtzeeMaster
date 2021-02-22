// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "Console.hpp"

#include <magic_enum.hpp>
#include <tabulate/table.hpp>

#include <iostream>

namespace YahtzeeMaster
{
Console::Console(Mode mode) : m_mode{ mode }
{
    // Do nothing
}

void Console::ProcessGame()
{
    if (m_mode == Mode::SINGLE_HUMAN || m_mode == Mode::SINGLE_COMPUTER)
    {
        m_game = std::make_unique<Game>(1);
    }
    else
    {
        m_game = std::make_unique<Game>(2);
    }

    m_game->Start();

    for (std::size_t i = 0; i < NUM_CATEGORIES; ++i)
    {
        switch (m_mode)
        {
            case Mode::SINGLE_HUMAN:
                PlayHumanTurn();
                break;
            case Mode::SINGLE_COMPUTER:
                PlayComputerTurn();
                break;
            case Mode::HUMAN_VS_COMPUTER:
                PlayHumanTurn();
                PlayComputerTurn();
                break;
            case Mode::COMPUTER_VS_COMPUTER:
                PlayComputerTurn();
                PlayComputerTurn();
                break;
        }
    }

    ShowResult();
}

void Console::PlayHumanTurn()
{
    ShowScoreCard();

    Player& player = m_game->GetCurrentPlayer();
    std::cout << "Round " << m_game->GetGameState().curRound << '\n';
    std::cout << m_game->GetGameState().curPlayerIdx + 1 << "P's turn\n";

    std::vector<int> rerollVals;
    rerollVals.reserve(NUM_DICES);

    for (int i = 0; i < NUM_ROLLS; ++i)
    {
        player.RollDices(i == 0 ? true : false, rerollVals);
        ShowDiceValues();

        if (i < NUM_ROLLS - 1)
        {
            rerollVals = ProcessReroll();
        }
    }

    ChooseCategory();
}

void Console::PlayComputerTurn()
{
}

void Console::ShowDiceValues() const
{
    Player& player = m_game->GetCurrentPlayer();

    std::cout << "Your dice values: ";
    std::array<int, NUM_DICES> diceVals = player.GetDiceValues();
    for (const auto& val : diceVals)
    {
        std::cout << val << " ";
    }
    std::cout << '\n';
    std::cout << "Remain reroll: " << player.GetRemainReroll() << "\n";
}

std::vector<int> Console::ProcessReroll()
{
    int numDicesReroll;

    std::cout << "How many dice are you going to reroll? ";
    std::cin >> numDicesReroll;

    std::vector<int> rerollVals;
    rerollVals.reserve(numDicesReroll);

    if (numDicesReroll > 0)
    {
        std::cout << "Select dice values to reroll: ";
        for (int i = 0; i < numDicesReroll; ++i)
        {
            int val;
            std::cin >> val;

            rerollVals.emplace_back(val);
        }
    }

    return rerollVals;
}

void Console::ChooseCategory()
{
    ShowScoresByDice();

    std::string categoryName;

    while (true)
    {
        Player& player = m_game->GetCurrentPlayer();

        std::cout << "Select category: ";
        std::cin >> categoryName;

        auto category = magic_enum::enum_cast<Category>(categoryName);
        if (category.has_value())
        {
            if (player.GetScoreCard().IsFilled(category.value()))
            {
                std::cout << categoryName << " is already filled!\n";
            }
            else
            {
                player.FillScoreCard(category.value());
                break;
            }
        }
        else
        {
            std::cout << "Invalid category!\n";
        }
    }
}

void Console::ShowScoreCard()
{
    tabulate::Table table;

    std::vector<variant<std::string, const char*, tabulate::Table>> title;
    title.reserve(NUM_CATEGORIES + 3);

    title.emplace_back("");
    for (int i = 0; i < NUM_UPPER_CATEGORIES; ++i)
    {
        const auto category = static_cast<Category>(i);
        title.emplace_back(std::string{ magic_enum::enum_name(category) });
    }
    title.emplace_back("BONUS");
    for (int i = NUM_UPPER_CATEGORIES; i < NUM_CATEGORIES; ++i)
    {
        const auto category = static_cast<Category>(i);
        title.emplace_back(std::string{ magic_enum::enum_name(category) });
    }
    title.emplace_back("TOTAL");
    table.add_row(title);

    const std::size_t numPlayers = m_game->GetNumPlayers();

    for (std::size_t i = 0; i < numPlayers; ++i)
    {
        Player& player = m_game->GetPlayer(i);
        const ScoreCard& scoreCard = player.GetScoreCard();

        std::vector<variant<std::string, const char*, tabulate::Table>> scores;
        scores.reserve(NUM_CATEGORIES + 3);

        scores.emplace_back(std::to_string(i + 1) + "P");
        for (int j = 0; j < NUM_UPPER_CATEGORIES; ++j)
        {
            scores.emplace_back(
                std::to_string(scoreCard.GetScore(static_cast<Category>(j))));
        }
        scores.emplace_back(std::to_string(scoreCard.GetUpperCategoryScore()) + "/" +
                            std::to_string(UPPER_SECTION_BONUS_CONDITION));
        for (int j = NUM_UPPER_CATEGORIES; j < NUM_CATEGORIES; ++j)
        {
            scores.emplace_back(
                std::to_string(scoreCard.GetScore(static_cast<Category>(j))));
        }
        scores.emplace_back(std::to_string(scoreCard.GetTotalScore()));
        table.add_row(scores);
    }

    for (int i = 0; i < NUM_UPPER_CATEGORIES; ++i)
    {
        table[0][i + 1].format().font_color(tabulate::Color::yellow);
    }
    table[0][NUM_UPPER_CATEGORIES + 1].format().font_color(tabulate::Color::blue);
    for (int i = NUM_UPPER_CATEGORIES; i < NUM_CATEGORIES; ++i)
    {
        table[0][i + 2].format().font_color(tabulate::Color::cyan);
    }
    table[0][NUM_CATEGORIES + 2].format().font_color(tabulate::Color::blue);

    for (std::size_t i = 1; i <= numPlayers; ++i)
    {
        table[i][0]
            .format()
            .font_color(tabulate::Color::magenta)
            .font_align(tabulate::FontAlign::center);
    }

    for (std::size_t i = 1; i <= numPlayers; ++i)
    {
        Player& player = m_game->GetPlayer(i - 1);
        const ScoreCard& scoreCard = player.GetScoreCard();
        tabulate::Color color;

        for (int j = 0; j < NUM_UPPER_CATEGORIES; ++j)
        {
            color = scoreCard.IsFilled(static_cast<Category>(j)) ? tabulate::Color::red
                                                                 : tabulate::Color::green;

            table[i][j + 1].format().font_color(color).font_align(
                tabulate::FontAlign::center);
        }
        color = scoreCard.GetUpperCategoryScore() > UPPER_SECTION_BONUS_CONDITION
                    ? tabulate::Color::green
                    : tabulate::Color::red;
        table[i][NUM_UPPER_CATEGORIES + 1].format().font_color(color).font_align(
            tabulate::FontAlign::center);
        for (int j = NUM_UPPER_CATEGORIES; j < NUM_CATEGORIES; ++j)
        {
            color = scoreCard.IsFilled(static_cast<Category>(j)) ? tabulate::Color::red
                                                                 : tabulate::Color::green;
            table[i][j + 2].format().font_color(color).font_align(
                tabulate::FontAlign::center);
        }
        table[i][NUM_CATEGORIES + 2]
            .format()
            .font_color(tabulate::Color::white)
            .font_align(tabulate::FontAlign::center);
    }

    std::cout << table << std::endl;
}

void Console::ShowScoresByDice()
{
    Player& player = m_game->GetCurrentPlayer();
    const ScoreCard& scoreCard = player.GetScoreCard();
    std::array<int, NUM_CATEGORIES> diceScores = player.GetScores();

    tabulate::Table table;

    std::vector<variant<std::string, const char*, tabulate::Table>> title;
    title.reserve(NUM_CATEGORIES + 2);

    for (int i = 0; i < NUM_UPPER_CATEGORIES; ++i)
    {
        const auto category = static_cast<Category>(i);
        title.emplace_back(std::string{ magic_enum::enum_name(category) });
    }
    title.emplace_back("BONUS");
    for (int i = NUM_UPPER_CATEGORIES; i < NUM_CATEGORIES; ++i)
    {
        const auto category = static_cast<Category>(i);
        title.emplace_back(std::string{ magic_enum::enum_name(category) });
    }
    title.emplace_back("TOTAL");
    table.add_row(title);

    std::vector<variant<std::string, const char*, tabulate::Table>> scores;
    scores.reserve(NUM_CATEGORIES + 2);

    for (int i = 0; i < NUM_UPPER_CATEGORIES; ++i)
    {
        const auto category = static_cast<Category>(i);

        if (scoreCard.IsFilled(category))
        {
            scores.emplace_back(std::to_string(scoreCard.GetScore(category)));
        }
        else
        {
            scores.emplace_back(std::to_string(diceScores[i]));
        }
    }
    scores.emplace_back(std::to_string(scoreCard.GetUpperCategoryScore()) + "/" +
                        std::to_string(UPPER_SECTION_BONUS_CONDITION));
    for (int i = NUM_UPPER_CATEGORIES; i < NUM_CATEGORIES; ++i)
    {
        const auto category = static_cast<Category>(i);

        if (scoreCard.IsFilled(category))
        {
            scores.emplace_back(std::to_string(scoreCard.GetScore(category)));
        }
        else
        {
            scores.emplace_back(std::to_string(diceScores[i]));
        }
    }
    scores.emplace_back(std::to_string(scoreCard.GetTotalScore()));
    table.add_row(scores);

    for (int i = 0; i < NUM_UPPER_CATEGORIES; ++i)
    {
        table[0][i].format().font_color(tabulate::Color::yellow);
    }
    table[0][NUM_UPPER_CATEGORIES].format().font_color(tabulate::Color::blue);
    for (int i = NUM_UPPER_CATEGORIES; i < NUM_CATEGORIES; ++i)
    {
        table[0][i + 1].format().font_color(tabulate::Color::cyan);
    }
    table[0][NUM_CATEGORIES + 1].format().font_color(tabulate::Color::blue);

    tabulate::Color color;

    for (int i = 0; i < NUM_UPPER_CATEGORIES; ++i)
    {
        color = scoreCard.IsFilled(static_cast<Category>(i)) ? tabulate::Color::red
                                                             : tabulate::Color::green;

        table[1][i].format().font_color(color).font_align(tabulate::FontAlign::center);
    }
    color = scoreCard.GetUpperCategoryScore() > UPPER_SECTION_BONUS_CONDITION
                ? tabulate::Color::green
                : tabulate::Color::red;
    table[1][NUM_UPPER_CATEGORIES].format().font_color(color).font_align(
        tabulate::FontAlign::center);
    for (int i = NUM_UPPER_CATEGORIES; i < NUM_CATEGORIES; ++i)
    {
        color = scoreCard.IsFilled(static_cast<Category>(i)) ? tabulate::Color::red
                                                             : tabulate::Color::green;
        table[1][i + 1].format().font_color(color).font_align(
            tabulate::FontAlign::center);
    }
    table[1][NUM_CATEGORIES + 1]
        .format()
        .font_color(tabulate::Color::white)
        .font_align(tabulate::FontAlign::center);

    std::cout << table << std::endl;
}

void Console::ShowResult()
{
    ShowScoreCard();

    const std::size_t numPlayers = m_game->GetNumPlayers();

    for (std::size_t i = 0; i < numPlayers; ++i)
    {
        if (m_game->GetPlayer(i).result == Result::WON)
        {
            std::cout << "Player " << (i + 1) << " Won!\n";
            break;
        }
    }
}
}  // namespace YahtzeeMaster