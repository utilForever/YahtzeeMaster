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
    pybind11::class_<GameManager>(
        m, "GameManager",
        R"pbdoc(This class monitors game and invokes method when a state is changed.)pbdoc")
        .def(pybind11::init<>())
        .def_static("process_next_step", &GameManager::ProcessNextStep,
                    R"pbdoc(Invokes method when a state is changed.

            Parameters
            ----------
            - game : The game context.
            - step : The next step.)pbdoc",
                    pybind11::arg("game"), pybind11::arg("step"));
}