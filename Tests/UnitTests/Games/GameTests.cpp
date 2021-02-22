// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <YahtzeeMaster/Games/Game.hpp>

using namespace YahtzeeMaster;

TEST_CASE("[Game] - GetGameState")
{
    GameConfig config;
    config.numPlayers = 2;

    Game game{ config };
    game.Start();

    GameState& gameState = game.GetGameState();
    CHECK_EQ(gameState.curPlayerIdx, 0);
}

TEST_CASE("[Game] - GetNumPlayers")
{
    Game game{ GameConfig{ 2 } };
    game.Start();

    CHECK_EQ(game.GetNumPlayers(), 2);
}

TEST_CASE("[Game] - RollDices")
{
    GameConfig config;
    config.numPlayers = 2;

    Game game{ config };
    game.Start();

    Player& curPlayer = game.GetCurrentPlayer();
    curPlayer.RollDices(true);

    std::array<int, NUM_DICES> values1 = curPlayer.GetDiceValues();
    for (auto& value : values1)
    {
        CHECK((value >= 1 && value <= 6));
    }

    curPlayer.RollDices(false);

    std::array<int, NUM_DICES> values2 = curPlayer.GetDiceValues();
    for (int i = 0; i < NUM_DICES; ++i)
    {
        CHECK_EQ(values1[i], values2[i]);
    }

    curPlayer.RollDices(false, { 2, 3 });
}

TEST_CASE("[Game] - Basic")
{
    GameConfig config;
    config.numPlayers = 2;

    Game game{ config };
    game.Start();

    for (std::size_t i = 0; i < config.numPlayers * NUM_CATEGORIES; ++i)
    {
        game.GetCurrentPlayer().RollDices();
        game.GetCurrentPlayer().FillScoreCard(static_cast<Category>(i / 2));
    }

    CHECK((game.GetGameState().players[0].result == Result::WON ||
           game.GetGameState().players[0].result == Result::LOST));
    CHECK((game.GetGameState().players[1].result == Result::WON ||
           game.GetGameState().players[1].result == Result::LOST));
}