// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Games/GameManager.hpp>
#include <YahtzeeMaster/Games/GameManager.hpp>

#include <pybind11/pybind11.h>

using namespace YahtzeeMaster;

void AddGameManager(pybind11::module& m)
{
    pybind11::class_<GameManager>(m, "GameManager")
        .def("ProcessNextStep", &GameManager::ProcessNextStep);
}