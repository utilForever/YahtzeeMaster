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
    //! Returns a list of values of the dice.
    //! \return A list of values of the dice.
    [[nodiscard]] std::array<int, NUM_DICES> GetDiceValues() const;

    //! Rolls a list of dices.
    void RollDices();

 private:
    std::array<Dice, NUM_DICES> m_dices;
    ScoreCard m_scoreCard;
};
}  // namespace YahtzeeMaster

#endif