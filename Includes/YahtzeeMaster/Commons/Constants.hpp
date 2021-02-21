// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef YAHTZEE_MASTER_CONSTANTS_HPP
#define YAHTZEE_MASTER_CONSTANTS_HPP

namespace YahtzeeMaster
{
//! The number of dices.
constexpr int NUM_DICES = 5;

//! The number of rolls.
constexpr int NUM_ROLLS = 3;

//! The number of categories.
constexpr int NUM_CATEGORIES = 13;

//! The value of the upper section to gain the bonus score.
constexpr int UPPER_SECTION_BONUS_CONDITION = 63;

//! The bonus of the upper section.
constexpr int UPPER_SECTION_BONUS = 35;
}  // namespace YahtzeeMaster

#endif