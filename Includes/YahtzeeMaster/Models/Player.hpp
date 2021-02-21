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
#include <functional>
#include <vector>

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

    //! Returns the score card.
    //! \return The score card.
    [[nodiscard]] const ScoreCard& GetScoreCard() const;

    //! Returns a list of values of the dice.
    //! \return A list of values of the dice.
    [[nodiscard]] std::array<int, NUM_DICES> GetDiceValues() const;

    //! Returns a list of scores according to the value of dices.
    //! \return A list of scores according to the value of dices.
    [[nodiscard]] std::array<int, NUM_CATEGORIES> GetScores() const;

    //! Returns the number of remain reroll.
    //! \return The number of remain reroll.
    [[nodiscard]] int GetRemainReroll() const;

    //! Sets a list of dice values (for testing purposes).
    //! \param diceValues A list of dice values to set.
    void SetDiceValues(std::vector<int> diceValues);

    //! Rolls a list of dices.
    //! \param rerollValues A list of dice values to roll.
    void RollDices(std::vector<int> rerollValues = {});

    //! Calculates a list of scores according to the value of dices.
    void CalculateScores();

    //! Fills a score to the score card.
    //! \param category The category to fill a score.
    void FillScoreCard(Category category);

    std::function<void()> processNextPlayerCallback;

    Result result = Result::INVALID;

 private:
    ScoreCard m_scoreCard;

    std::array<Dice, NUM_DICES> m_dices;
    std::array<int, NUM_CATEGORIES> m_scores{};

    int m_numRoll = 0;
};
}  // namespace YahtzeeMaster

#endif