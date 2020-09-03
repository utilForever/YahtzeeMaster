// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Enums/GameEnums.hpp>
#include <YahtzeeMaster/Enums/GameEnums.hpp>

#include <pybind11/pybind11.h>

using namespace YahtzeeMaster;

void AddGameEnums(pybind11::module& m)
{
    pybind11::enum_<Step>(m, "Step")
        .value("INVALID", Step::INVALID)
        .value("PLAY_ROUND", Step::PLAY_ROUND)
        .value("COMPLETE", Step::COMPLETE)
        .export_values();

    pybind11::enum_<Category>(m, "Category")
        .value("ACES", Category::ACES)
        .value("TWOS", Category::TWOS)
        .value("THREES", Category::THREES)
        .value("FOURS", Category::FOURS)
        .value("FIVES", Category::FIVES)
        .value("SIXES", Category::SIXES)
        .value("THREE_OF_A_KIND", Category::THREE_OF_A_KIND)
        .value("FOUR_OF_A_KIND", Category::FOUR_OF_A_KIND)
        .value("FULL_HOUSE", Category::FULL_HOUSE)
        .value("SMALL_STRAIGHT", Category::SMALL_STRAIGHT)
        .value("LARGE_STRAIGHT", Category::LARGE_STRAIGHT)
        .value("YAHTZEE", Category::YAHTZEE)
        .value("CHANCE", Category::CHANCE)
        .export_values();

    pybind11::enum_<Result>(m, "Result")
        .value("INVALID", Result::INVALID)
        .value("WON", Result::WON)
        .value("LOST", Result::LOST)
        .export_values();
}