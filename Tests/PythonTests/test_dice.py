"""
Copyright (c) 2020 Chris Ohk

I am making my contributions/submissions to this project solely in our
personal capacity and am not conveying any rights to any intellectual
property of any third parties.
"""

import pyYahtzee


def test_dice_roll():
    dice = pyYahtzee.Dice()

    dice.roll()
    assert 1 <= dice.get_value() <= 6
