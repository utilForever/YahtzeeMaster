// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef YAHTZEE_MASTER_DICE_HPP
#define YAHTZEE_MASTER_DICE_HPP

namespace YahtzeeMaster
{
//!
//! \brief Dice class.
//!
//! Dice (singular die or dice) are small, throwable objects with marked
//! sides that can rest in multiple positions. They are used for generating
//! random numbers, commonly as part of tabletop games, including dice games,
//! board games, role-playing games, and games of chance.
//!
class Dice
{
 public:
    //! Rolls a dice.
    void Roll();

 private:
    int m_value = 0;
};
}  // namespace YahtzeeMaster

#endif