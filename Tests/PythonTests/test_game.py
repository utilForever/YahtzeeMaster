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
    cur_player.roll_dices([0, 1, 2, 3, 4])

    values1 = cur_player.get_dice_values()
    for value in values1:
        assert 1 <= value <= 6

    cur_player.roll_dices([0, 1, 3])

    values2 = cur_player.get_dice_values()
    assert values1[2] == values2[2]
    assert values1[4] == values2[4]

    cur_player.roll_dices([2, 3])

    values3 = cur_player.get_dice_values()
    assert values2[0] == values3[0]
    assert values2[1] == values3[1]
    assert values2[4] == values3[4]

    cur_player.roll_dices([0, 1, 2, 3, 4])

    values4 = cur_player.get_dice_values()
    for i in range(0, pyYahtzee.NUM_DICES):
        assert values3[i] == values4[i]


def test_game_basic():
    config = pyYahtzee.GameConfig()
    config.num_players = 2

    game = pyYahtzee.Game(config)
    game.start()

    for i in range(config.num_players * pyYahtzee.NUM_CATEGORIES):
        game.get_current_player().roll_dices([0, 1, 2, 3, 4])
        game.get_current_player().fill_score_card(pyYahtzee.Category(int(i / 2)))

    assert game.get_game_state().players[0].result == pyYahtzee.Result.WON or game.get_game_state(
    ).players[0].result == pyYahtzee.Result.LOST
    assert game.get_game_state().players[1].result == pyYahtzee.Result.WON or game.get_game_state(
    ).players[1].result == pyYahtzee.Result.LOST
