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

    //! Constructs a Console instance with \p mode.
    //! \param mode The game mode such as single and versus.
    Console(Mode mode);

    //! Process a Yahtzee game.
    void ProcessGame();

 private:
    //! Plays a turn for human.
    void PlayHumanTurn();

    //! Plays a turn for computer.
    void PlayComputerTurn();

    // Shows a list of dice values.
    void ShowDiceValues() const;

    //! Processes a reroll.
    std::vector<int> ProcessReroll();

    //! Chooses a category to record on the score card.
    void ChooseCategory();

    //! Shows a score card.
    void ShowScoreCard();

    //! Shows a list of scores by dice.
    void ShowScoresByDice();

    std::unique_ptr<Game> m_game;

    Mode m_mode;
};
}  // namespace YahtzeeMaster

#endif