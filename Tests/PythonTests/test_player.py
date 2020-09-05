"""
Copyright (c) 2020 Chris Ohk

I am making my contributions/submissions to this project solely in our
personal capacity and am not conveying any rights to any intellectual
property of any third parties.
"""

import pyYahtzee


def test_player_roll_dices():
    player = pyYahtzee.Player()

    player.roll_dices([0, 1, 2, 3, 4])

    values = player.get_dice_values()
    for value in values:
        assert 1 <= value <= 6


def test_player_calculate_scores():
    player = pyYahtzee.Player()

    player.set_dice_values([6, 1, 2, 3, 4])
    player.calculate_scores()

    scores = player.get_scores()
    assert scores[pyYahtzee.Category.ACES] == 1
    assert scores[pyYahtzee.Category.TWOS] == 2
    assert scores[pyYahtzee.Category.THREES] == 3
    assert scores[pyYahtzee.Category.FOURS] == 4
    assert scores[pyYahtzee.Category.FIVES] == 0
    assert scores[pyYahtzee.Category.SIXES] == 6
    assert scores[pyYahtzee.Category.THREE_OF_A_KIND] == 0
    assert scores[pyYahtzee.Category.FOUR_OF_A_KIND] == 0
    assert scores[pyYahtzee.Category.FULL_HOUSE] == 0
    assert scores[pyYahtzee.Category.SMALL_STRAIGHT] == 30
    assert scores[pyYahtzee.Category.LARGE_STRAIGHT] == 0
    assert scores[pyYahtzee.Category.YAHTZEE] == 0
    assert scores[pyYahtzee.Category.CHANCE] == 16

    player.set_dice_values([2, 5, 5, 2, 5])
    player.calculate_scores()

    scores = player.get_scores()
    assert scores[pyYahtzee.Category.ACES] == 0
    assert scores[pyYahtzee.Category.TWOS] == 4
    assert scores[pyYahtzee.Category.THREES] == 0
    assert scores[pyYahtzee.Category.FOURS] == 0
    assert scores[pyYahtzee.Category.FIVES] == 15
    assert scores[pyYahtzee.Category.SIXES] == 0
    assert scores[pyYahtzee.Category.THREE_OF_A_KIND] == 19
    assert scores[pyYahtzee.Category.FOUR_OF_A_KIND] == 0
    assert scores[pyYahtzee.Category.FULL_HOUSE] == 25
    assert scores[pyYahtzee.Category.SMALL_STRAIGHT] == 0
    assert scores[pyYahtzee.Category.LARGE_STRAIGHT] == 0
    assert scores[pyYahtzee.Category.YAHTZEE] == 0
    assert scores[pyYahtzee.Category.CHANCE] == 19

    player.set_dice_values([6, 6, 6, 6, 6])
    player.calculate_scores()

    scores = player.get_scores()
    assert scores[pyYahtzee.Category.ACES] == 0
    assert scores[pyYahtzee.Category.TWOS] == 0
    assert scores[pyYahtzee.Category.THREES] == 0
    assert scores[pyYahtzee.Category.FOURS] == 0
    assert scores[pyYahtzee.Category.FIVES] == 0
    assert scores[pyYahtzee.Category.SIXES] == 30
    assert scores[pyYahtzee.Category.THREE_OF_A_KIND] == 30
    assert scores[pyYahtzee.Category.FOUR_OF_A_KIND] == 30
    assert scores[pyYahtzee.Category.FULL_HOUSE] == 0
    assert scores[pyYahtzee.Category.SMALL_STRAIGHT] == 0
    assert scores[pyYahtzee.Category.LARGE_STRAIGHT] == 0
    assert scores[pyYahtzee.Category.YAHTZEE] == 50
    assert scores[pyYahtzee.Category.CHANCE] == 30
