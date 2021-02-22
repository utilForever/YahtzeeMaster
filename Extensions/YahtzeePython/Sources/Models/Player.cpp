// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Models/Player.hpp>
#include <YahtzeeMaster/Models/Player.hpp>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

using namespace YahtzeeMaster;

void AddPlayer(pybind11::module& m)
{
    pybind11::class_<Player>(
        m, "Player",
        R"pbdoc(This class stores various information that used in Yahtzee game.)pbdoc")
        .def(pybind11::init<>())
        .def("initialize", &Player::Initialize,
             R"pbdoc(Initializes player to play each round.)pbdoc")
        .def("get_score_card", &Player::GetScoreCard,
             R"pbdoc(Returns the score card.)pbdoc")
        .def("get_dice_values", &Player::GetDiceValues,
             R"pbdoc(Returns a list of values of the dice.)pbdoc")
        .def("get_scores", &Player::GetScores,
             R"pbdoc(Returns a list of scores according to the value of dices.)pbdoc")
        .def("set_dice_values", &Player::SetDiceValues,
             R"pbdoc(Sets a list of values of the dice (for testing purposes).

            Parameters
            ----------
            - dice_values : A list of values of the dice to set.)pbdoc",
             pybind11::arg("dice_values"))
        .def("roll_dices", &Player::RollDices, R"pbdoc(Rolls a list of dices.

            Parameters
            ----------
            - is_first: A flag to indicate it is first roll.
            - reroll_values : A list of dice values to roll.)pbdoc",
             pybind11::arg("is_first") = false,
             pybind11::arg("reroll_values") = std::vector<int>{})
        .def("calculate_scores", &Player::CalculateScores,
             R"pbdoc(Calculates a list of scores according to the value of dices.)pbdoc")
        .def("fill_score_card", &Player::FillScoreCard, R"pbdoc(

            Parameters
            ----------
            - category : The category to fill a score.)pbdoc",
             pybind11::arg("category"))
        .def_readwrite("result", &Player::result);
}