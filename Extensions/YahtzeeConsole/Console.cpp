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
        // Human turn
        if (m_mode == Mode::HUMAN_VS_COMPUTER)
        {
            PlayHumanTurn();
        }
        else
        {
            PlayComputerTurn();
        }
    }
}

void Console::PlayHumanTurn()
{
    Player& player = m_game->GetCurrentPlayer();
    player.RollDices();

    ShowDiceValues();

    int choice;
    std::cout << "1. Reroll (Remain: " << player.GetRemainReroll() << ")\n";
    std::cout << "2. Choose category\n";
    std::cout << "3. Show score card\n";
    std::cout << "Choice: ";
    std::cin >> choice;

    if (choice == 1)
    {
    }
    else if (choice == 2)
    {
    }
    else if (choice == 3)
    {
    }
    else
    {
    }
}

void Console::PlayComputerTurn()
{
}

void Console::ShowDiceValues() const
{
    Player& player = m_game->GetCurrentPlayer();

    std::cout << "Your dice values: ";
    const std::array<int, NUM_DICES> diceVals = player.GetDiceValues();
    for (const auto& val : diceVals)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

void Console::ShowScoreCard()
{
    tabulate::Table table;

    const std::size_t numPlayers = m_game->GetNumPlayers();

    std::vector<variant<std::string, const char*, tabulate::Table>> title;
    title.reserve(numPlayers + 1);

    title.emplace_back("Categories");
    for (std::size_t i = 0; i < numPlayers; ++i)
    {
        title.emplace_back(std::to_string(i + 1) + "P");
    }
    table.add_row(title);

    std::vector<variant<std::string, const char*, tabulate::Table>> scores;
    scores.reserve(numPlayers + 1);

    for (std::size_t i = 0; i < NUM_CATEGORIES; ++i)
    {
        const auto category = static_cast<Category>(i);

        scores.clear();

        scores.emplace_back(std::string{ magic_enum::enum_name(category) });
        for (std::size_t j = 0; j < numPlayers; ++j)
        {
            const ScoreCard& scoreCard = m_game->GetPlayer(j).GetScoreCard();
            scores.emplace_back(std::to_string(scoreCard.GetScore(category)));
        }
        table.add_row(scores);
    }

    table[0][0].format().font_color(tabulate::Color::red);
    for (std::size_t i = 1; i <= numPlayers; ++i)
    {
        table[0][i]
            .format()
            .font_color(tabulate::Color::magenta)
            .font_align(tabulate::FontAlign::center);
    }

    for (std::size_t i = 1; i <= NUM_CATEGORIES; ++i)
    {
        const tabulate::Color color =
            (i - 1 <= Category::SIXES) ? tabulate::Color::yellow : tabulate::Color::cyan;
        table[i][0].format().font_color(color);
    }

    for (std::size_t i = 1; i <= NUM_CATEGORIES; ++i)
    {
        for (std::size_t j = 1; j <= numPlayers; ++j)
        {
            const tabulate::Color color =
                m_game->GetPlayer(j - 1).GetScoreCard().IsFilled(
                    static_cast<Category>(i - 1))
                    ? tabulate::Color::green
                    : tabulate::Color::none;

            table[i][j].format().font_color(color).font_align(
                tabulate::FontAlign::center);
        }
    }

    std::cout << table << std::endl;
}
}  // namespace YahtzeeMaster