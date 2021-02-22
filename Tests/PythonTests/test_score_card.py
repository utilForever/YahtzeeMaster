"""
Copyright (c) 2020 Chris Ohk

I am making my contributions/submissions to this project solely in our
personal capacity and am not conveying any rights to any intellectual
property of any third parties.
"""

import pyYahtzee


def test_score_card_fill_score():
    config = pyYahtzee.GameConfig()
    config.num_players = 1

    game = pyYahtzee.Game(config)
    game.start()

    assert game.get_game_state().cur_round == 1

    cur_player = game.get_current_player()

    cur_player.roll_dices(True)
    cur_player.fill_score_card(pyYahtzee.Category.ACES)
    assert game.get_game_state().cur_round == 2

    cur_player.roll_dices(True)
    cur_player.fill_score_card(pyYahtzee.Category.ACES)
    assert game.get_game_state().cur_round == 2


def test_score_card_get_total_score():
    score_card = pyYahtzee.ScoreCard()

    score_card.fill_score(pyYahtzee.Category.ACES, 3)
    score_card.fill_score(pyYahtzee.Category.TWOS, 6)
    score_card.fill_score(pyYahtzee.Category.THREES, 9)
    score_card.fill_score(pyYahtzee.Category.FOURS, 12)
    score_card.fill_score(pyYahtzee.Category.FIVES, 15)
    assert score_card.get_total_score() == 45

    score_card.fill_score(pyYahtzee.Category.SIXES, 18)
    assert score_card.get_total_score() == 98


def test_score_card_three_of_a_kind():
    dice_values1 = [1, 2, 4, 4, 5]
    dice_values2 = [1, 4, 4, 4, 5]

    assert pyYahtzee.ScoreCard().is_three_of_a_kind(dice_values1) is False
    assert pyYahtzee.ScoreCard().is_three_of_a_kind(dice_values2) is True


def test_score_card_four_of_a_kind():
    dice_values1 = [1, 4, 4, 4, 5]
    dice_values2 = [1, 4, 4, 4, 4]

    assert pyYahtzee.ScoreCard().is_four_of_a_kind(dice_values1) is False
    assert pyYahtzee.ScoreCard().is_four_of_a_kind(dice_values2) is True


def test_score_card_full_house():
    dice_values1 = [2, 4, 4, 4, 5]
    dice_values2 = [2, 2, 4, 4, 4]

    assert pyYahtzee.ScoreCard().is_full_house(dice_values1) is False
    assert pyYahtzee.ScoreCard().is_full_house(dice_values2) is True


def test_score_card_small_straight():
    dice_values1 = [1, 3, 4, 4, 6]
    dice_values2 = [2, 2, 3, 4, 5]

    assert pyYahtzee.ScoreCard().is_small_straight(dice_values1) is False
    assert pyYahtzee.ScoreCard().is_small_straight(dice_values2) is True


def test_score_card_large_straight():
    dice_values1 = [2, 2, 3, 4, 5]
    dice_values2 = [2, 3, 4, 5, 6]

    assert pyYahtzee.ScoreCard().is_large_straight(dice_values1) is False
    assert pyYahtzee.ScoreCard().is_large_straight(dice_values2) is True


def test_score_card_yahtzee():
    dice_values1 = [3, 4, 4, 4, 4]
    dice_values2 = [4, 4, 4, 4, 4]

    assert pyYahtzee.ScoreCard().is_yahtzee(dice_values1) is False
    assert pyYahtzee.ScoreCard().is_yahtzee(dice_values2) is True
