// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "Console.hpp"

#include <lyra/lyra.hpp>

using namespace YahtzeeMaster;

int main(int argc, char* argv[])
{
    std::size_t mode = 0;
    bool showHelp = false;

    // Process CLI
    const auto cli = lyra::cli() | lyra::help(showHelp) |
                     lyra::opt(mode, "mode")["-m"]["--mode"](
                         "The game mode. (0 - Single Human, 1 - Single Com, 2 - Human vs "
                         "Com, 3 - Com vs Com)");
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

    if (mode != 0)
    {
        std::cerr << "Sorry, the console supports single human mode only." << std::endl;
        std::cerr << "I'll implement other modes ASAP." << std::endl;
        return EXIT_SUCCESS;
    }

    Console console{ static_cast<Console::Mode>(mode) };
    console.ProcessGame();

    return EXIT_SUCCESS;
}
