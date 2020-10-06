// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <YahtzeeMaster/Games/Game.hpp>

#include <lyra/lyra.hpp>
#include <tabulate/table.hpp>

#include <string>

using namespace YahtzeeMaster;

void ShowScoreCard(const Player& player)
{
    tabulate::Table table;
    const std::array<int, NUM_CATEGORIES> scores = player.GetScores();

    for (std::size_t i = 0; i < NUM_CATEGORIES; ++i)
    {
        table.add_row({ std::to_string(scores[i]) });
    }
}

void ProcessGame(const std::size_t mode, const std::size_t numPlayers)
{
    Game game{ numPlayers };
    game.Start();

    // Human vs Computer(s)
    if (mode == 1)
    {
    }
    // Computer vs Computer(s)
    else
    {
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