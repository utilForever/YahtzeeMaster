// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef YAHTZEE_MASTER_GAME_STATE_HPP
#define YAHTZEE_MASTER_GAME_STATE_HPP

#include <YahtzeeMaster/Models/Player.hpp>

#include <vector>

namespace YahtzeeMaster
{
//!
//! \brief GameState struct.
//!
//! This struct stores the information of the game state of all players.
//!
struct GameState
{
    std::vector<Player> players;
    std::size_t curPlayerIdx = 0;
};
}  // namespace YahtzeeMaster

#endif