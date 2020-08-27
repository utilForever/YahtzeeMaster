// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <YahtzeeMaster/Games/Game.hpp>

using namespace YahtzeeMaster;

TEST_CASE("[Game] - GetGameState")
{
    Game game;
    GameState& state = game.GetGameState();

    state.players.emplace_back(Player{});
    state.players[0].RollDices();

    std::array<int, NUM_DICES> values1 = state.players[0].GetDiceValues();
    for (auto& value : values1)
    {
        CHECK((value >= 1 && value <= 6));
    }

    state.players[0].RollDices({ 0, 1, 3 });

    std::array<int, NUM_DICES> values2 = state.players[0].GetDiceValues();
    CHECK_EQ(values1[2], values2[2]);
    CHECK_EQ(values1[4], values2[4]);

    state.players[0].RollDices({ 2, 3 });

    std::array<int, NUM_DICES> values3 = state.players[0].GetDiceValues();
    CHECK_EQ(values2[0], values3[0]);
    CHECK_EQ(values2[1], values3[1]);
    CHECK_EQ(values2[4], values3[4]);

    state.players[0].RollDices();

    std::array<int, NUM_DICES> values4 = state.players[0].GetDiceValues();
    for (std::size_t i = 0; i < static_cast<std::size_t>(NUM_DICES); ++i)
    {
        CHECK_EQ(values3[i], values4[i]);
    }
}