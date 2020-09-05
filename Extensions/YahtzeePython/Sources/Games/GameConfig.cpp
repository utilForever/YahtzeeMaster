// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Games/GameConfig.hpp>
#include <YahtzeeMaster/Games/GameConfig.hpp>

#include <pybind11/pybind11.h>

using namespace YahtzeeMaster;

void AddGameConfig(pybind11::module& m)
{
    pybind11::class_<GameConfig>(
        m, "GameConfig",
        R"pbdoc(This struct holds all configuration values to create a new Game instance.)pbdoc")
        .def(pybind11::init<>())
        .def_readwrite("num_players", &GameConfig::numPlayers);
}