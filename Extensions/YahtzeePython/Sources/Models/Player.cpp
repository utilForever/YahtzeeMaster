// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Models/Player.hpp>
#include <YahtzeeMaster/Models/Player.hpp>

#include <pybind11/pybind11.h>

using namespace YahtzeeMaster;

void AddPlayer(pybind11::module& m)
{
    pybind11::class_<Player>(m, "Player")
        .def("Initialize", &Player::Initialize)
        .def("GetScoreCard", &Player::GetScoreCard)
        .def("GetDiceValues", &Player::GetDiceValues)
        .def("GetScores", &Player::GetScores)
        .def("SetDiceValues", &Player::SetDiceValues)
        .def("RollDices", &Player::RollDices)
        .def("CalculateScores", &Player::CalculateScores)
        .def("FillScoreCard", &Player::FillScoreCard);
}