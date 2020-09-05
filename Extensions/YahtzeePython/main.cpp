// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Commons/Constants.hpp>
#include <Enums/GameEnums.hpp>
#include <Games/Game.hpp>
#include <Games/GameConfig.hpp>
#include <Games/GameManager.hpp>
#include <Games/GameState.hpp>
#include <Models/Dice.hpp>
#include <Models/Player.hpp>
#include <Models/ScoreCard.hpp>

#include <pybind11/pybind11.h>

PYBIND11_MODULE(pyYahtzee, m)
{
    m.doc() = R"pbdoc(Yahtzee simulator with some reinforcement learning)pbdoc";

    AddConstants(m);
    AddGameEnums(m);
    AddGame(m);
    AddGameConfig(m);
    AddGameManager(m);
    AddGameState(m);
    AddDice(m);
    AddPlayer(m);
    AddScoreCard(m);
}