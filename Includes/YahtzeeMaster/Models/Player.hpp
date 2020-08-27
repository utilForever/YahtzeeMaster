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

    //! Rolls a list of dices.
    //! \param diceIndices A list of indices of dice to roll.
    void RollDices(std::initializer_list<std::size_t> diceIndices = { 0, 1, 2, 3, 4 });

 private:
    std::array<Dice, NUM_DICES> m_dices;
    int m_numReroll = 0;

    ScoreCard m_scoreCard;
};
}  // namespace YahtzeeMaster

#endif