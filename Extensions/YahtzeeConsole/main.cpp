// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <YahtzeeMaster/Games/Game.hpp>

#include <lyra/lyra.hpp>
#include <magic_enum.hpp>
#include <tabulate/table.hpp>

#include <string>

using namespace YahtzeeMaster;

void ShowScoreCard(Game& game)
{
    tabulate::Table table;

    const std::size_t numPlayers = game.GetNumPlayers();

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
            const ScoreCard& scoreCard = game.GetPlayer(j).GetScoreCard();
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
            const tabulate::Color color = game.GetPlayer(j - 1).GetScoreCard().IsFilled(
                                              static_cast<Category>(i - 1))
                                              ? tabulate::Color::green
                                              : tabulate::Color::none;

            table[i][j].format().font_color(color).font_align(
                tabulate::FontAlign::center);
        }
    }

    std::cout << table << std::endl;
}

void PlayHumanTurn(Game& game)
{
    Player& player = game.GetCurrentPlayer();
    player.RollDices();

    std::cout << "Your dice values: ";
    const std::array<int, NUM_DICES> diceVals = player.GetDiceValues();
    for (const auto& val : diceVals)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

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

void PlayComputerTurn(Game& game)
{
    (void)game;
}

void ProcessGame(const std::size_t mode, const std::size_t numPlayers)
{
    Game game{ numPlayers };
    game.Start();

    for (std::size_t i = 0; i < NUM_CATEGORIES; ++i)
    {
        for (std::size_t j = 0; j < numPlayers; ++j)
        {
            // Human turn
            if (mode == 1 && j == 0)
            {
                PlayHumanTurn(game);
            }
            else
            {
                PlayComputerTurn(game);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    std::size_t mode = 1, numPlayers = 2;
    bool showHelp = false;

    // Process CLI
    const auto cli =
        lyra::cli() | lyra::help(showHelp) |
        lyra::opt(mode, "mode")["-m"]["--mode"](
            "The game mode. (1 - Human vs Computer(s), 2 - Computer vs Computer(s)") |
        lyra::opt(numPlayers, "numPlayers")["-n"]["--num"]("The number of players.");
    const auto result = cli.parse({ argc, argv });

    if (!result)
    {
        std::cerr << "Error in command line: " << result.errorMessage() << std::endl;
        std::cerr << cli << std::endl;
        return EXIT_FAILURE;
    }

    if (showHelp)
    {
        std::cout << cli << std::endl;
        return EXIT_SUCCESS;
    }

    ProcessGame(mode, numPlayers);

    return EXIT_SUCCESS;
}