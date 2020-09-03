// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Models/ScoreCard.hpp>
#include <YahtzeeMaster/Models/ScoreCard.hpp>

#include <pybind11/pybind11.h>

using namespace YahtzeeMaster;

void AddScoreCard(pybind11::module& m)
{
    pybind11::class_<ScoreCard>(m, "ScoreCard")
        .def(pybind11::init<>())
        .def("FillScore", &ScoreCard::FillScore)
        .def("GetTotalScore", &ScoreCard::GetTotalScore)
        .def("IsThreeOfAKind", &ScoreCard::IsThreeOfAKind)
        .def("IsFourOfAKind", &ScoreCard::IsFourOfAKind)
        .def("IsFullHouse", &ScoreCard::IsFullHouse)
        .def("IsSmallStraight", &ScoreCard::IsSmallStraight)
        .def("IsLargeStraight", &ScoreCard::IsLargeStraight)
        .def("IsYahtzee", &ScoreCard::IsYahtzee);
}