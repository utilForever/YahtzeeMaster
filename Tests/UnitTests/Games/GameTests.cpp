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

    std::array<int, 5> values = state.players[0].GetDiceValues();
    for (auto& value : values)
    {
        CHECK((value >= 1 && value <= 6));
    }
}