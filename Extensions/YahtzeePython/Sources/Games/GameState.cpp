// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Games/GameState.hpp>
#include <YahtzeeMaster/Games/GameState.hpp>

#include <pybind11/pybind11.h>

using namespace YahtzeeMaster;

void AddGameState(pybind11::module& m)
{
    pybind11::class_<GameState>(m, "GameState");
}