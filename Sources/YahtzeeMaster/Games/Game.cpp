// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <YahtzeeMaster/Games/Game.hpp>
#include <YahtzeeMaster/Games/GameManager.hpp>

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

Player& Game::GetCurrentPlayer()
{
    return m_gameState.players[m_gameState.curPlayerIdx];
}

void Game::Start()
{
    // Initialize player related variables
    for (std::size_t i = 0; i < m_config.numPlayers; ++i)
    {
        m_gameState.players.emplace_back(Player{});
    }

    // Initialize game related variables
    m_gameState.curPlayerIdx = 0;
    m_gameState.curRound = 1;

    // Set next step
    nextStep = Step::PLAY_ROUND;
    GameManager::ProcessNextStep(*this, nextStep);
}

void Game::PlayRound()
{
    // Initialize the current player
    GetCurrentPlayer().Initialize();
}
}  // namespace YahtzeeMaster