"""
Copyright (c) 2020 Chris Ohk

I am making my contributions/submissions to this project solely in our
personal capacity and am not conveying any rights to any intellectual
property of any third parties.
"""

import pyYahtzee


def test_game_manager_basic():
    config = pyYahtzee.GameConfig()
    config.num_players = 2

    game = pyYahtzee.Game(config)
    game_manager = pyYahtzee.GameManager()

    game_manager.process_next_step(game, pyYahtzee.Step.INVALID)
    assert game.step == pyYahtzee.Step.INVALID

    game.start()