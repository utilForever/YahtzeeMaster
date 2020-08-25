// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <YahtzeeMaster/Models/Dice.hpp>

using namespace YahtzeeMaster;

TEST_CASE("[Dice] - Roll")
{
    Dice dice;

    dice.Roll();
    CHECK((dice.GetValue() >= 1 && dice.GetValue() <= 6));
}