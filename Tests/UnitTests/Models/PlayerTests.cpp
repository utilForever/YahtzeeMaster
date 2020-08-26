// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <YahtzeeMaster/Models/Player.hpp>

using namespace YahtzeeMaster;

TEST_CASE("[Player] - RollDices")
{
    Player player;

    player.RollDices();

    std::array<int, NUM_DICES> values = player.GetDiceValues();
    for (auto& value : values)
    {
        CHECK((value >= 1 && value <= 6));
    }
}