// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef YAHTZEE_MASTER_GAME_MANAGER_HPP
#define YAHTZEE_MASTER_GAME_MANAGER_HPP

#include <YahtzeeMaster/Enums/GameEnums.hpp>
#include <YahtzeeMaster/Games/Game.hpp>

namespace YahtzeeMaster
{
//!
//! \brief GameManager class.
//!
//! This class monitors game and invokes method when a state is changed.
//!
class GameManager
{
 public:
    //! Invokes method when a state is changed.
    //! \param game The game context.
    //! \param step The next step.
    static void ProcessNextStep(Game& game, Step step);
};
}  // namespace YahtzeeMaster

#endif
