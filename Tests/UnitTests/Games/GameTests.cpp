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
    Game game{ 2 };
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
    curPlayer.RollDices();

    std::array<int, NUM_DICES> values1 = curPlayer.GetDiceValues();
    for (auto& value : values1)
    {
        CHECK((value >= 1 && value <= 6));
    }

    curPlayer.RollDices({ 0, 1, 3 });

    std::array<int, NUM_DICES> values2 = curPlayer.GetDiceValues();
    CHECK_EQ(values1[2], values2[2]);
    CHECK_EQ(values1[4], values2[4]);

    curPlayer.RollDices({ 2, 3 });

    std::array<int, NUM_DICES> values3 = curPlayer.GetDiceValues();
    CHECK_EQ(values2[0], values3[0]);
    CHECK_EQ(values2[1], values3[1]);
    CHECK_EQ(values2[4], values3[4]);

    curPlayer.RollDices();

    std::array<int, NUM_DICES> values4 = curPlayer.GetDiceValues();
    for (std::size_t i = 0; i < static_cast<std::size_t>(NUM_DICES); ++i)
    {
        CHECK_EQ(values3[i], values4[i]);
    }
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