// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <YahtzeeMaster/Games/Game.hpp>
#include <YahtzeeMaster/Models/ScoreCard.hpp>

using namespace YahtzeeMaster;

TEST_CASE("[ScoreCard] - FillScore")
{
    GameConfig config;
    config.numPlayers = 1;

    Game game{ config };
    game.Start();

    CHECK_EQ(game.GetGameState().curRound, 1);

    game.GetCurrentPlayer().RollDices();
    game.GetCurrentPlayer().FillScoreCard(Category::ACES);
    CHECK_EQ(game.GetGameState().curRound, 2);

    game.GetCurrentPlayer().RollDices();
    game.GetCurrentPlayer().FillScoreCard(Category::ACES);
    CHECK_EQ(game.GetGameState().curRound, 2);
}

TEST_CASE("[ScoreCard] - GetScore")
{
    ScoreCard scoreCard;

    scoreCard.FillScore(Category::TWOS, 10);
    scoreCard.FillScore(Category::FOUR_OF_A_KIND, 21);

    CHECK_EQ(scoreCard.GetScore(Category::ACES), 0);
    CHECK_EQ(scoreCard.GetScore(Category::TWOS), 10);
    CHECK_EQ(scoreCard.GetScore(Category::THREE_OF_A_KIND), 0);
    CHECK_EQ(scoreCard.GetScore(Category::FOUR_OF_A_KIND), 21);
}

TEST_CASE("[ScoreCard] - GetTotalScore")
{
    ScoreCard scoreCard;

    scoreCard.FillScore(Category::ACES, 3);
    scoreCard.FillScore(Category::TWOS, 6);
    scoreCard.FillScore(Category::THREES, 9);
    scoreCard.FillScore(Category::FOURS, 12);
    scoreCard.FillScore(Category::FIVES, 15);
    CHECK_EQ(scoreCard.GetTotalScore(), 45);

    scoreCard.FillScore(Category::SIXES, 18);
    CHECK_EQ(scoreCard.GetTotalScore(), 98);
}

TEST_CASE("[ScoreCard] - IsFilled")
{
    ScoreCard scoreCard;

    for (std::size_t i = 0; i < NUM_CATEGORIES; ++i)
    {
        CHECK_FALSE(scoreCard.IsFilled(static_cast<Category>(i)));
    }

    scoreCard.FillScore(Category::ACES, 4);
    scoreCard.FillScore(Category::FULL_HOUSE, 26);

    for (std::size_t i = 0; i < NUM_CATEGORIES; ++i)
    {
        if (i == 0 || i == 8)
        {
            CHECK(scoreCard.IsFilled(static_cast<Category>(i)));
        }
        else
        {
            CHECK_FALSE(scoreCard.IsFilled(static_cast<Category>(i)));
        }
    }
}

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

TEST_CASE("[ScoreCard] - FullHouse")
{
    const std::array<int, NUM_DICES> diceValues1{ 2, 4, 4, 4, 5 };
    const std::array<int, NUM_DICES> diceValues2{ 2, 2, 4, 4, 4 };

    CHECK_EQ(ScoreCard::IsFullHouse(diceValues1), false);
    CHECK_EQ(ScoreCard::IsFullHouse(diceValues2), true);
}

TEST_CASE("[ScoreCard] - SmallStraight")
{
    const std::array<int, NUM_DICES> diceValues1{ 1, 3, 4, 4, 6 };
    const std::array<int, NUM_DICES> diceValues2{ 2, 2, 3, 4, 5 };

    CHECK_EQ(ScoreCard::IsSmallStraight(diceValues1), false);
    CHECK_EQ(ScoreCard::IsSmallStraight(diceValues2), true);
}

TEST_CASE("[ScoreCard] - LargeStraight")
{
    const std::array<int, NUM_DICES> diceValues1{ 2, 2, 3, 4, 5 };
    const std::array<int, NUM_DICES> diceValues2{ 2, 3, 4, 5, 6 };

    CHECK_EQ(ScoreCard::IsLargeStraight(diceValues1), false);
    CHECK_EQ(ScoreCard::IsLargeStraight(diceValues2), true);
}

TEST_CASE("[ScoreCard] - Yahtzee")
{
    const std::array<int, NUM_DICES> diceValues1{ 3, 4, 4, 4, 4 };
    const std::array<int, NUM_DICES> diceValues2{ 4, 4, 4, 4, 4 };

    CHECK_EQ(ScoreCard::IsYahtzee(diceValues1), false);
    CHECK_EQ(ScoreCard::IsYahtzee(diceValues2), true);
}