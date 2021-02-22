// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef YAHTZEE_MASTER_GAME_CONFIG_HPP
#define YAHTZEE_MASTER_GAME_CONFIG_HPP

#include <cstddef>

namespace YahtzeeMaster
{
//!
//! \brief GameConfig struct.
//!
//! This struct holds all configuration values to create a new Game instance.
//!
struct GameConfig
{
    //! Default constructor.
    GameConfig() = default;

    //! Constructs a game config with given \p _numPlayers.
    //! \param _numPlayers The number of players.
    explicit GameConfig(std::size_t _numPlayers) : numPlayers(_numPlayers)
    {
        // Do nothing
    }

    std::size_t numPlayers = 0;
};
}  // namespace YahtzeeMaster

#endif