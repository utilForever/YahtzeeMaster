// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <YahtzeeMaster/Models/ScoreCard.hpp>

using namespace YahtzeeMaster;

TEST_CASE("[ScoreCard] - ThreeOfAKind")
{
    const std::array<int, NUM_DICES> diceValues1{ 1, 2, 4, 4, 5 };
    const std::array<int, NUM_DICES> diceValues2{ 1, 4, 4, 4, 5 };

    CHECK_EQ(ScoreCard::IsThreeOfAKind(diceValues1), false);
    CHECK_EQ(ScoreCard::IsThreeOfAKind(diceValues2), true);
}

TEST_CASE("[ScoreCard] - FourOfAKind")
{
    const std::array<int, NUM_DICES> diceValues1{ 1, 4, 4, 4, 5 };
    const std::array<int, NUM_DICES> diceValues2{ 1, 4, 4, 4, 4 };

    CHECK_EQ(ScoreCard::IsFourOfAKind(diceValues1), false);
    CHECK_EQ(ScoreCard::IsFourOfAKind(diceValues2), true);
}