// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Models/ScoreCard.hpp>
#include <YahtzeeMaster/Models/ScoreCard.hpp>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

using namespace YahtzeeMaster;

void AddScoreCard(pybind11::module& m)
{
    pybind11::class_<ScoreCard>(
        m, "ScoreCard",
        R"pbdoc(The Yahtzee scorecard contains 13 different category boxes and in each round, after the third roll, the player must choose one of these categories. The score entered in the box depends on how well the five dice match the scoring rule for the category. Details of the scoring rules for each category are given below. As an example, one of the categories is called Three of a Kind. The scoring rule for this category means that a player only scores if at least three of the five dice are the same value. The game is completed after 13 rounds by each player, with each of the 13 boxes filled. The total score is calculated by summing all thirteen boxes, together with any bonuses.)pbdoc")
        .def(pybind11::init<>())
        .def("fill_score", &ScoreCard::FillScore, R"pbdoc(Fills a score.

            Parameters
            ----------
            - category : The category to fill a score.
            - score : The value of score.)pbdoc",
             pybind11::arg("category"), pybind11::arg("score"))
        .def("get_total_score", &ScoreCard::GetTotalScore,
             R"pbdoc(Returns the total score.)pbdoc")
        .def_static(
            "is_three_of_a_kind", &ScoreCard::IsThreeOfAKind,
            R"pbdoc(Checks that a list of dices satisfies Three Of A Kind condition.

            Parameters
            ----------
            - dice_values : A list of values of the dice.)pbdoc",
            pybind11::arg("dice_values"))
        .def_static(
            "is_four_of_a_kind", &ScoreCard::IsFourOfAKind,
            R"pbdoc(Checks that a list of dices satisfies Four Of A Kind condition.

            Parameters
            ----------
            - dice_values : A list of values of the dice.)pbdoc",
            pybind11::arg("dice_values"))
        .def_static("is_full_house", &ScoreCard::IsFullHouse,
                    R"pbdoc(Checks that a list of dices satisfies Full House condition.

            Parameters
            ----------
            - dice_values : A list of values of the dice.)pbdoc",
                    pybind11::arg("dice_values"))
        .def_static(
            "is_small_straight", &ScoreCard::IsSmallStraight,
            R"pbdoc(Checks that a list of dices satisfies Small Straight condition.

            Parameters
            ----------
            - dice_values : A list of values of the dice.)pbdoc",
            pybind11::arg("dice_values"))
        .def_static(
            "is_large_straight", &ScoreCard::IsLargeStraight,
            R"pbdoc(Checks that a list of dices satisfies Large Straight condition.

            Parameters
            ----------
            - dice_values : A list of values of the dice.)pbdoc",
            pybind11::arg("dice_values"))
        .def_static("is_yahtzee", &ScoreCard::IsYahtzee,
                    R"pbdoc(Checks that a list of dices satisfies Yahtzee condition.

            Parameters
            ----------
            - dice_values : A list of values of the dice.)pbdoc",
                    pybind11::arg("dice_values"));
}