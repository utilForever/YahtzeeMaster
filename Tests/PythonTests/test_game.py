"""
Copyright (c) 2020 Chris Ohk

I am making my contributions/submissions to this project solely in our
personal capacity and am not conveying any rights to any intellectual
property of any third parties.
"""

import pyYahtzee


def test_game_get_game_state():
    config = pyYahtzee.GameConfig()
    config.num_players = 2

    game = pyYahtzee.Game(config)
    game.start()

    game_state = game.get_game_state()
    assert game_state.cur_player_idx == 0


def test_game_roll_dices():
    config = pyYahtzee.GameConfig()
    config.num_players = 2

    game = pyYahtzee.Game(config)
    game.start()

    cur_player = game.get_current_player()
    cur_player.roll_dices(True)

    values1 = cur_player.get_dice_values()
    for value in values1:
        assert 1 <= value <= 6

    cur_player.roll_dices(False)

    values2 = cur_player.get_dice_values()
    for i in range(0, pyYahtzee.NUM_DICES):
        assert values1[i] == values2[i]


def test_game_basic():
    config = pyYahtzee.GameConfig()
    config.num_players = 2

    game = pyYahtzee.Game(config)
    game.start()

    for i in range(config.num_players * pyYahtzee.NUM_CATEGORIES):
        game.get_current_player().roll_dices(True)
        game.get_current_player().fill_score_card(pyYahtzee.Category(int(i / 2)))

    assert game.get_game_state().players[0].result == pyYahtzee.Result.WON or game.get_game_state(
    ).players[0].result == pyYahtzee.Result.LOST
    assert game.get_game_state().players[1].result == pyYahtzee.Result.WON or game.get_game_state(
    ).players[1].result == pyYahtzee.Result.LOST
