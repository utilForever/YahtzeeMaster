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
    pybind11::class_<Dice>(m, "Dice")
        .def("GetValue", &Dice::GetValue)
        .def("SetValue", &Dice::SetValue)
        .def("Roll", &Dice::Roll);
}