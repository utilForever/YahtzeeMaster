// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef YAHTZEE_MASTER_SCORE_CARD_HPP
#define YAHTZEE_MASTER_SCORE_CARD_HPP

#include <YahtzeeMaster/Commons/Constants.hpp>
#include <YahtzeeMaster/Enums/GameEnums.hpp>

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

    //! Fills a score.
    //! \param category The category to fill a score.
    //! \param score The value of score.
    //! \return true if a score is filled successfully, false otherwise.
    bool FillScore(Category category, int score);

    //! Returns the score of \p category.
    //! \param category The category to get score.
    //! \return The score of \p category.
    [[nodiscard]] int GetScore(Category category) const;

    //! Returns the score of upper categories.
    //! \return The score of upper categories.
    [[nodiscard]] int GetUpperCategoryScore() const;

    //! Returns the total score.
    //! \return The total score.
    [[nodiscard]] int GetTotalScore() const;

    //! Checks the value of \p category is filled.
    //! \param category The category to check that it is filled.
    //! \return true if the value of \p category is filled, false otherwise.
    [[nodiscard]] bool IsFilled(Category category) const;

    //! Checks that a list of dices satisfies "Three Of A Kind" condition.
    //! \param diceValues A list of values of the dice.
    //! \return true if a list of dices satisfies the condition, false otherwise.
    static bool IsThreeOfAKind(const std::array<int, NUM_DICES>& diceValues);

    //! Checks that a list of dices satisfies "Four Of A Kind" condition.
    //! \param diceValues A list of values of the dice.
    //! \return true if a list of dices satisfies the condition, false otherwise.
    static bool IsFourOfAKind(const std::array<int, NUM_DICES>& diceValues);

    //! Checks that a list of dices satisfies "Full House" condition.
    //! \param diceValues A list of values of the dice.
    //! \return true if a list of dices satisfies the condition, false otherwise.
    static bool IsFullHouse(const std::array<int, NUM_DICES>& diceValues);

    //! Checks that a list of dices satisfies "Small Straight" condition.
    //! \param diceValues A list of values of the dice.
    //! \return true if a list of dices satisfies the condition, false otherwise.
    static bool IsSmallStraight(const std::array<int, NUM_DICES>& diceValues);

    //! Checks that a list of dices satisfies "Large Straight" condition.
    //! \param diceValues A list of values of the dice.
    //! \return true if a list of dices satisfies the condition, false otherwise.
    static bool IsLargeStraight(const std::array<int, NUM_DICES>& diceValues);

    //! Checks that a list of dices satisfies "Yahtzee" condition.
    //! \param diceValues A list of values of the dice.
    //! \return true if a list of dices satisfies the condition, false otherwise.
    static bool IsYahtzee(const std::array<int, NUM_DICES>& diceValues);

 private:
    std::array<int, NUM_CATEGORIES> m_scores{};
    std::array<bool, NUM_CATEGORIES> m_scoreMarks{};
};
}  // namespace YahtzeeMaster

#endif