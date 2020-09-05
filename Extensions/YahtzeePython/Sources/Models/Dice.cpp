// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Models/Dice.hpp>
#include <YahtzeeMaster/Models/Dice.hpp>

#include <pybind11/pybind11.h>

using namespace YahtzeeMaster;

void AddDice(pybind11::module& m)
{
    pybind11::class_<Dice>(
        m, "Dice",
        R"pbdoc(Dice (singular die or dice) are small, throwable objects with marked sides that can rest in multiple positions. They are used for generating random numbers, commonly as part of tabletop games, including dice games, board games, role-playing games, and games of chance.)pbdoc")
        .def(pybind11::init<>())
        .def("get_value", &Dice::GetValue, R"pbdoc(Returns the value of the dice.)pbdoc")
        .def("set_value", &Dice::SetValue,
             R"pbdoc(Sets the value of the dice (for testing purposes).

            Parameters
            ----------
            - value : The value of the dice.)pbdoc",
             pybind11::arg("value"))
        .def("roll", &Dice::Roll, R"pbdoc(Rolls a dice.)pbdoc");
}