// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Games/Game.hpp>
#include <YahtzeeMaster/Games/Game.hpp>

#include <pybind11/pybind11.h>

using namespace YahtzeeMaster;

void AddGame(pybind11::module& m)
{
    pybind11::class_<Game>(m, "Game")
        .def(pybind11::init<const GameConfig&>())
        .def("GetGameState", &Game::GetGameState)
        .def("GetCurrentPlayer", &Game::GetCurrentPlayer)
        .def("Start", &Game::Start)
        .def("PlayRound", &Game::PlayRound)
        .def("CalculateResult", &Game::CalculateResult);
}