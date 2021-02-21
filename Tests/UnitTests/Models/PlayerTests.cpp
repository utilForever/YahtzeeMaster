// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <YahtzeeMaster/Enums/GameEnums.hpp>
#include <YahtzeeMaster/Models/Player.hpp>

using namespace YahtzeeMaster;

TEST_CASE("[Player] - RollDices")
{
    Player player;

    player.RollDices(true);

    std::array<int, NUM_DICES> values = player.GetDiceValues();
    for (auto& value : values)
    {
        CHECK((value >= 1 && value <= 6));
    }
}

TEST_CASE("[Player] - CalculateScores")
{
    Player player;

    player.SetDiceValues({ 6, 1, 3, 2, 4 });
    player.CalculateScores();

    std::array<int, NUM_CATEGORIES> scores = player.GetScores();
    CHECK_EQ(scores[Category::ACES], 1);
    CHECK_EQ(scores[Category::TWOS], 2);
    CHECK_EQ(scores[Category::THREES], 3);
    CHECK_EQ(scores[Category::FOURS], 4);
    CHECK_EQ(scores[Category::FIVES], 0);
    CHECK_EQ(scores[Category::SIXES], 6);
    CHECK_EQ(scores[Category::THREE_OF_A_KIND], 0);
    CHECK_EQ(scores[Category::FOUR_OF_A_KIND], 0);
    CHECK_EQ(scores[Category::FULL_HOUSE], 0);
    CHECK_EQ(scores[Category::SMALL_STRAIGHT], 30);
    CHECK_EQ(scores[Category::LARGE_STRAIGHT], 0);
    CHECK_EQ(scores[Category::YAHTZEE], 0);
    CHECK_EQ(scores[Category::CHANCE], 16);

    player.SetDiceValues({ 2, 5, 5, 2, 5 });
    player.CalculateScores();

    scores = player.GetScores();
    CHECK_EQ(scores[Category::ACES], 0);
    CHECK_EQ(scores[Category::TWOS], 4);
    CHECK_EQ(scores[Category::THREES], 0);
    CHECK_EQ(scores[Category::FOURS], 0);
    CHECK_EQ(scores[Category::FIVES], 15);
    CHECK_EQ(scores[Category::SIXES], 0);
    CHECK_EQ(scores[Category::THREE_OF_A_KIND], 19);
    CHECK_EQ(scores[Category::FOUR_OF_A_KIND], 0);
    CHECK_EQ(scores[Category::FULL_HOUSE], 25);
    CHECK_EQ(scores[Category::SMALL_STRAIGHT], 0);
    CHECK_EQ(scores[Category::LARGE_STRAIGHT], 0);
    CHECK_EQ(scores[Category::YAHTZEE], 0);
    CHECK_EQ(scores[Category::CHANCE], 19);

    player.SetDiceValues({ 6, 6, 6, 6, 6 });
    player.CalculateScores();

    scores = player.GetScores();
    CHECK_EQ(scores[Category::ACES], 0);
    CHECK_EQ(scores[Category::TWOS], 0);
    CHECK_EQ(scores[Category::THREES], 0);
    CHECK_EQ(scores[Category::FOURS], 0);
    CHECK_EQ(scores[Category::FIVES], 0);
    CHECK_EQ(scores[Category::SIXES], 30);
    CHECK_EQ(scores[Category::THREE_OF_A_KIND], 30);
    CHECK_EQ(scores[Category::FOUR_OF_A_KIND], 30);
    CHECK_EQ(scores[Category::FULL_HOUSE], 0);
    CHECK_EQ(scores[Category::SMALL_STRAIGHT], 0);
    CHECK_EQ(scores[Category::LARGE_STRAIGHT], 0);
    CHECK_EQ(scores[Category::YAHTZEE], 50);
    CHECK_EQ(scores[Category::CHANCE], 30);
}