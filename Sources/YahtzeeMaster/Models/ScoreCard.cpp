// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <YahtzeeMaster/Models/ScoreCard.hpp>

namespace YahtzeeMaster
{
ScoreCard::ScoreCard()
{
    m_scores.fill(0);
    m_scoreMarks.fill(false);
}

bool ScoreCard::IsThreeOfAKind(const std::array<int, NUM_DICES>& diceValues)
{
    return (diceValues[0] == diceValues[1] && diceValues[1] == diceValues[2]) ||
           (diceValues[1] == diceValues[2] && diceValues[2] == diceValues[3]) ||
           (diceValues[2] == diceValues[3] && diceValues[3] == diceValues[4]);
}
}  // namespace YahtzeeMaster