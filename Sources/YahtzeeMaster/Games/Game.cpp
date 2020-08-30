// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <YahtzeeMaster/Games/Game.hpp>
#include <YahtzeeMaster/Games/GameManager.hpp>

#include <algorithm>

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
    // Create callback to process the next player
    auto processNextPlayerCallback = [this]() {
        // Increase the index of the current player
        ++m_gameState.curPlayerIdx;
        m_gameState.curPlayerIdx %= m_gameState.players.size();

        if (m_gameState.curPlayerIdx == 0)
        {
            ++m_gameState.curRound;
        }

        if (m_gameState.curRound > NUM_CATEGORIES)
        {
            // Set next step
            nextStep = Step::COMPLETE;
            GameManager::ProcessNextStep(*this, nextStep);
        }
    };

    // Initialize player related variables
    for (std::size_t i = 0; i < m_config.numPlayers; ++i)
    {
        m_gameState.players.emplace_back(Player{});
        m_gameState.players[i].processNextPlayerCallback = processNextPlayerCallback;
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

void Game::CalculateResult()
{
    std::vector<int> scores;
    scores.reserve(m_gameState.players.size());

    // Collect total scores
    for (std::size_t i = 0; i < m_config.numPlayers; ++i)
    {
        scores.emplace_back(m_gameState.players[i].GetScoreCard().GetTotalScore());
    }

    // Find the maximum value of total scores
    const auto result = std::max_element(scores.begin(), scores.end());
    const std::size_t idx = std::distance(scores.begin(), result);

    // Set the result
    for (std::size_t i = 0; i < m_config.numPlayers; ++i)
    {
        m_gameState.players[i].result =
            (scores[i] == scores[idx]) ? Result::WON : Result::LOST;
    }
}
}  // namespace YahtzeeMaster