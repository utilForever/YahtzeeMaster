// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Commons/Constants.hpp>
#include <YahtzeeMaster/Commons/Constants.hpp>

#include <pybind11/pybind11.h>

using namespace YahtzeeMaster;

void AddConstants(pybind11::module& m)
{
    m.attr("NUM_DICES") = pybind11::int_(NUM_DICES);
    m.attr("NUM_ROLLS") = pybind11::int_(NUM_ROLLS);
    m.attr("NUM_CATEGORIES") = pybind11::int_(NUM_CATEGORIES);
    m.attr("UPPER_SECTION_BONUS_CONDITION") =
        pybind11::int_(UPPER_SECTION_BONUS_CONDITION);
    m.attr("UPPER_SECTION_BONUS") = pybind11::int_(UPPER_SECTION_BONUS);
}