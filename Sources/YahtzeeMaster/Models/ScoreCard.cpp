// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <YahtzeeMaster/Models/ScoreCard.hpp>

#include <algorithm>
#include <numeric>

namespace YahtzeeMaster
{
ScoreCard::ScoreCard()
{
    m_scores.fill(0);
    m_scoreMarks.fill(false);
}

bool ScoreCard::FillScore(Category category, int score)
{
    if (m_scoreMarks[category] == true)
    {
        return false;
    }

    m_scores[category] = score;
    m_scoreMarks[category] = true;

    return true;
}

int ScoreCard::GetTotalScore() const
{
    const int bonus = (m_scores[Category::ACES] + m_scores[Category::TWOS] +
                       m_scores[Category::THREES] + m_scores[Category::FOURS] +
                       m_scores[Category::FIVES] + m_scores[Category::SIXES]) >=
                              UPPER_SECTION_BONUS_CONDITION
                          ? UPPER_SECTION_BONUS
                          : 0;

    return std::accumulate(m_scores.begin(), m_scores.end(), 0) + bonus;
}

bool ScoreCard::IsThreeOfAKind(const std::array<int, NUM_DICES>& diceValues)
{
    return (diceValues[0] == diceValues[1] && diceValues[1] == diceValues[2]) ||
           (diceValues[1] == diceValues[2] && diceValues[2] == diceValues[3]) ||
           (diceValues[2] == diceValues[3] && diceValues[3] == diceValues[4]);
}

bool ScoreCard::IsFourOfAKind(const std::array<int, NUM_DICES>& diceValues)
{
    return (diceValues[0] == diceValues[1] && diceValues[1] == diceValues[2] &&
            diceValues[2] == diceValues[3]) ||
           (diceValues[1] == diceValues[2] && diceValues[2] == diceValues[3] &&
            diceValues[3] == diceValues[4]);
}

bool ScoreCard::IsFullHouse(const std::array<int, NUM_DICES>& diceValues)
{
    return (diceValues[0] == diceValues[1] && diceValues[1] != diceValues[2] &&
            diceValues[2] == diceValues[3] && diceValues[3] == diceValues[4]) ||
           (diceValues[0] == diceValues[1] && diceValues[1] == diceValues[2] &&
            diceValues[2] != diceValues[3] && diceValues[3] == diceValues[4]);
}

bool ScoreCard::IsSmallStraight(const std::array<int, NUM_DICES>& diceValues)
{
    std::array<int, NUM_DICES> values = diceValues;
    [[maybe_unused]] auto last = std::unique(values.begin(), values.end());

    return (values[0] + 1 == values[1] && values[1] + 1 == values[2] &&
            values[2] + 1 == values[3]);
}

bool ScoreCard::IsLargeStraight(const std::array<int, NUM_DICES>& diceValues)
{
    return (diceValues[0] + 1 == diceValues[1] && diceValues[1] + 1 == diceValues[2] &&
            diceValues[2] + 1 == diceValues[3] && diceValues[3] + 1 == diceValues[4]);
}

bool ScoreCard::IsYahtzee(const std::array<int, NUM_DICES>& diceValues)
{
    return (diceValues[0] == diceValues[1] && diceValues[1] == diceValues[2] &&
            diceValues[2] == diceValues[3] && diceValues[3] == diceValues[4]);
}
}  // namespace YahtzeeMaster