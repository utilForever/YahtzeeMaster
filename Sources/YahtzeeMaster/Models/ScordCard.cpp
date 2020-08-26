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
}  // namespace YahtzeeMaster