// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef YAHTZEE_MASTER_PLAYER_HPP
#define YAHTZEE_MASTER_PLAYER_HPP

#include <YahtzeeMaster/Commons/Constants.hpp>
#include <YahtzeeMaster/Models/Dice.hpp>
#include <YahtzeeMaster/Models/ScoreCard.hpp>

#include <array>
#include <initializer_list>

namespace YahtzeeMaster
{
//!
//! \brief Player class.
//!
//! This class stores various information that used in Yahtzee game.
//!
class Player
{
 public:
    //! Initializes player to play each round.
    void Initialize();

    //! Returns a list of values of the dice.
    //! \return A list of values of the dice.
    [[nodiscard]] std::array<int, NUM_DICES> GetDiceValues() const;

    //! Returns a list of scores according to the value of dices.
    //! \return A list of scores according to the value of dices.
    [[nodiscard]] std::array<int, NUM_CATEGORIES> GetScores() const;

    //! Sets a list of values of the dice (for testing purposes).
    //! \param diceValues A list of values of the dice to set.
    void SetDiceValues(std::initializer_list<int> diceValues);

    //! Rolls a list of dices.
    //! \param diceIndices A list of indices of dice to roll.
    void RollDices(std::initializer_list<std::size_t> diceIndices = { 0, 1, 2, 3, 4 });

    //! Calculates a list of scores according to the value of dices.
    void CalculateScores();

    //! Fills a score to the score card.
    //! \param category The category to fill a score.
    void FillScoreCard(Category category);

 private:
    ScoreCard m_scoreCard;

    std::array<Dice, NUM_DICES> m_dices;
    std::array<int, NUM_CATEGORIES> m_scores{};

    int m_numReroll = 0;
};
}  // namespace YahtzeeMaster

#endif