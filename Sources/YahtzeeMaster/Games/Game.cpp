// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <YahtzeeMaster/Games/Game.hpp>

namespace YahtzeeMaster
{
Game::Game(const GameConfig& config) : m_config(config)
{
    m_gameState.players.reserve(config.numPlayers);
}

GameState& Game::GetGameState()
{
    return m_gameState;
}

void Game::Start()
{
    // Initialize variables
    for (std::size_t i = 0; i < m_config.numPlayers; ++i)
    {
        m_gameState.players.emplace_back(Player{});
    }
}
}  // namespace YahtzeeMaster