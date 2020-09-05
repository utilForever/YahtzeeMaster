// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <Games/Game.hpp>
#include <YahtzeeMaster/Games/Game.hpp>

#include <pybind11/functional.h>
#include <pybind11/pybind11.h>

using namespace YahtzeeMaster;

void AddGame(pybind11::module& m)
{
    pybind11::class_<Game>(
        m, "Game",
        R"pbdoc(This class processes the game, Yahtzee. Yahtzee is a dice game made by Milton Bradley (now owned by Hasbro), which was first marketed as Yatzie by the National Association Service of Toledo, Ohio, in the early 1940s. It was marketed under the name of Yahtzee by game entrepreneur Edwin S. Lowe in 1956. The game is a development of earlier dice games such as Poker Dice, Yacht and Generala. It is also similar to Yatzy, which is popular in Scandinavia.)pbdoc")
        .def(pybind11::init<const GameConfig&>(),
             R"pbdoc(Constructs game with given game config.

            Parameters
            ----------
            - config : The game config holds all configuration values.)pbdoc",
             pybind11::arg("config"))
        .def("get_game_state", &Game::GetGameState,
             R"pbdoc(Returns the game state.)pbdoc")
        .def("get_current_player", &Game::GetCurrentPlayer,
             R"pbdoc(Returns the current player.)pbdoc")
        .def("start", &Game::Start, R"pbdoc(Starts the game.)pbdoc")
        .def("play_round", &Game::PlayRound, R"pbdoc(Plays round for each player.)pbdoc")
        .def("calculate_result", &Game::CalculateResult,
             R"pbdoc(Calculates the result.)pbdoc")
        .def_readwrite("step", &Game::step)
        .def_readwrite("next_step", &Game::nextStep);
}