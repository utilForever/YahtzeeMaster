// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef YAHTZEE_MASTER_CONSOLE_HPP
#define YAHTZEE_MASTER_CONSOLE_HPP

#include <YahtzeeMaster/Games/Game.hpp>

#include <memory>

namespace YahtzeeMaster
{
class Console
{
 public:
    enum class Mode
    {
        SINGLE_HUMAN,
        SINGLE_COMPUTER,
        HUMAN_VS_COMPUTER,
        COMPUTER_VS_COMPUTER
    };

    //! Constructs a Console instance with \p mode and \p numPlayers.
    //! \param mode The game mode (human vs computer, computer vs computer).
    //! \param numPlayers The number of player.
    Console(Mode mode, std::size_t numPlayers);

    //! Process a Yahtzee game.
    void ProcessGame();

    void PlayHumanTurn();
    void PlayComputerTurn();

    void ShowScoreCard();

 private:
    // Shows a list of dice values.
    void ShowDiceValues() const;

    std::unique_ptr<Game> m_game;

    Mode m_mode;
    std::size_t m_numPlayers;
};
}  // namespace YahtzeeMaster

#endif