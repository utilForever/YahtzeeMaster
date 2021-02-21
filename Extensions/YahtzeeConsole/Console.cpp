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
}

void Console::PlayHumanTurn()
{
    ShowScoreCard();

    Player& player = m_game->GetCurrentPlayer();

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
    title.reserve(NUM_CATEGORIES + 1);

    title.emplace_back("");
    for (std::size_t i = 0; i < NUM_CATEGORIES; ++i)
    {
        const auto category = static_cast<Category>(i);
        title.emplace_back(std::string{ magic_enum::enum_name(category) });
    }
    table.add_row(title);

    const std::size_t numPlayers = m_game->GetNumPlayers();

    for (std::size_t i = 0; i < numPlayers; ++i)
    {
        Player& player = m_game->GetPlayer(i);
        std::array<int, NUM_CATEGORIES> diceScores = player.GetScores();

        std::vector<variant<std::string, const char*, tabulate::Table>> scores;
        scores.reserve(NUM_CATEGORIES + 1);

        scores.emplace_back(std::to_string(i + 1) + "P");
        for (std::size_t j = 0; j < NUM_CATEGORIES; ++j)
        {
            scores.emplace_back(std::to_string(diceScores[j]));
        }

        table.add_row(scores);
    }

    for (std::size_t i = 1; i <= NUM_CATEGORIES; ++i)
    {
        const tabulate::Color color =
            (i - 1 <= Category::SIXES) ? tabulate::Color::yellow : tabulate::Color::cyan;
        table[0][i].format().font_color(color);
    }

    for (std::size_t i = 1; i <= numPlayers; ++i)
    {
        table[i][0]
            .format()
            .font_color(tabulate::Color::magenta)
            .font_align(tabulate::FontAlign::center);
    }

    for (std::size_t i = 1; i <= numPlayers; ++i)
    {
        for (std::size_t j = 1; j <= NUM_CATEGORIES; ++j)
        {
            const tabulate::Color color =
                m_game->GetPlayer(i - 1).GetScoreCard().IsFilled(
                    static_cast<Category>(j - 1))
                    ? tabulate::Color::red
                    : tabulate::Color::green;

            table[i][j].format().font_color(color).font_align(
                tabulate::FontAlign::center);
        }
    }

    std::cout << table << std::endl;
}

void Console::ShowScoresByDice()
{
    Player& player = m_game->GetCurrentPlayer();
    std::array<int, NUM_CATEGORIES> diceScores = player.GetScores();

    tabulate::Table table;

    std::vector<variant<std::string, const char*, tabulate::Table>> title;
    title.reserve(NUM_CATEGORIES + 1);

    for (std::size_t i = 0; i < NUM_CATEGORIES; ++i)
    {
        const auto category = static_cast<Category>(i);
        title.emplace_back(std::string{ magic_enum::enum_name(category) });
    }
    table.add_row(title);

    std::vector<variant<std::string, const char*, tabulate::Table>> scores;
    scores.reserve(1);

    for (std::size_t i = 0; i < NUM_CATEGORIES; ++i)
    {
        scores.emplace_back(std::to_string(diceScores[i]));
    }
    table.add_row(scores);

    for (std::size_t i = 0; i < NUM_CATEGORIES; ++i)
    {
        const tabulate::Color color =
            (i <= Category::SIXES) ? tabulate::Color::yellow : tabulate::Color::cyan;
        table[0][i].format().font_color(color);
    }

    table[1][0]
        .format()
        .font_color(tabulate::Color::magenta)
        .font_align(tabulate::FontAlign::center);

    for (std::size_t i = 0; i < NUM_CATEGORIES; ++i)
    {
        const tabulate::Color color =
            m_game->GetCurrentPlayer().GetScoreCard().IsFilled(static_cast<Category>(i))
                ? tabulate::Color::red
                : tabulate::Color::green;

        table[1][i].format().font_color(color).font_align(tabulate::FontAlign::center);
    }

    std::cout << table << std::endl;
}
}  // namespace YahtzeeMaster