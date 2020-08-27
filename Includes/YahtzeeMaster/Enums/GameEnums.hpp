// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef YAHTZEE_MASTER_GAME_ENUMS_HPP
#define YAHTZEE_MASTER_GAME_ENUMS_HPP

namespace YahtzeeMaster
{
//! \brief An enumerator for identifying the step.
enum class Step
{
    INVALID,
    PLAY_ROUND,
    COMPLETE
};
}  // namespace YahtzeeMaster

#endif