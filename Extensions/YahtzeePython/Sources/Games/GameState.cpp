// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Games/GameState.hpp>
#include <YahtzeeMaster/Games/GameState.hpp>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

using namespace YahtzeeMaster;

void AddGameState(pybind11::module& m)
{
    pybind11::class_<GameState>(
        m, "GameState",
        R"pbdoc(This struct stores the information of the game state of all players.)pbdoc")
        .def(pybind11::init<>())
        .def_readwrite("players", &GameState::players)
        .def_readwrite("cur_player_idx", &GameState::curPlayerIdx)
        .def_readwrite("cur_round", &GameState::curRound);
}