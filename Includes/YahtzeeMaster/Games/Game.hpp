// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef YAHTZEE_MASTER_GAME_HPP
#define YAHTZEE_MASTER_GAME_HPP

#include <YahtzeeMaster/Games/GameState.hpp>

namespace YahtzeeMaster
{
//!
//! \brief Game class.
//!
//! This class processes the game, Yahtzee. Yahtzee is a dice game made by
//! Milton Bradley (now owned by Hasbro), which was first marketed as Yatzie by
//! the National Association Service of Toledo, Ohio, in the early 1940s. It was
//! marketed under the name of Yahtzee by game entrepreneur Edwin S. Lowe in
//! 1956. The game is a development of earlier dice games such as Poker Dice,
//! Yacht and Generala. It is also similar to Yatzy, which is popular in
//! Scandinavia.
//!
class Game
{
 public:
    //! Gets the game state.
    //! \return The game state.
    [[nodiscard]] GameState& GetGameState();

    //! Starts the game.
    void Start();

 private:
    GameState m_gameState;
};
}  // namespace YahtzeeMaster

#endif