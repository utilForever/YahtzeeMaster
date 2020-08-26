// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef YAHTZEE_MASTER_SCORE_CARD_HPP
#define YAHTZEE_MASTER_SCORE_CARD_HPP

#include <YahtzeeMaster/Commons/Constants.hpp>

#include <array>

namespace YahtzeeMaster
{
//!
//! \brief ScordCard class.
//!
//! The Yahtzee scorecard contains 13 different category boxes and in each
//! round, after the third roll, the player must choose one of these categories.
//! The score entered in the box depends on how well the five dice match the
//! scoring rule for the category. Details of the scoring rules for each
//! category are given below. As an example, one of the categories is called
//! Three of a Kind. The scoring rule for this category means that a player only
//! scores if at least three of the five dice are the same value. The game is
//! completed after 13 rounds by each player, with each of the 13 boxes filled.
//! The total score is calculated by summing all thirteen boxes, together with
//! any bonuses.
//!
class ScoreCard
{
 public:
    //! Default constructor.
    ScoreCard();

 private:
    std::array<int, NUM_CATEGORIES> m_scores{};
    std::array<bool, NUM_CATEGORIES> m_scoreMarks{};
};
}  // namespace YahtzeeMaster

#endif