// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <YahtzeeMaster/Games/GameManager.hpp>

using namespace YahtzeeMaster;

TEST_CASE("[GameManager] - Basic")
{
    GameConfig config;
    config.numPlayers = 2;

    Game game{ config };

    GameManager::ProcessNextStep(game, Step::INVALID);
    CHECK_EQ(game.step, Step::INVALID);

    game.Start();
    CHECK_EQ(game.step, Step::PLAY_ROUND);

    for (std::size_t i = 0; i < config.numPlayers * NUM_CATEGORIES; ++i)
    {
        game.GetCurrentPlayer().RollDices();
        game.GetCurrentPlayer().FillScoreCard(static_cast<Category>(i / 2));
    }

    CHECK_EQ(game.step, Step::COMPLETE);
}