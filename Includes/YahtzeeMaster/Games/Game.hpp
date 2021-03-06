// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef YAHTZEE_MASTER_GAME_HPP
#define YAHTZEE_MASTER_GAME_HPP

#include <YahtzeeMaster/Enums/GameEnums.hpp>
#include <YahtzeeMaster/Games/GameConfig.hpp>
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
    //! Constructs game with given \p config.
    //! \param config The game config holds all configuration values.
    explicit Game(const GameConfig& config);

    //! Returns the game state.
    //! \return The game state.
    [[nodiscard]] GameState& GetGameState();

    //! Returns the number of players.
    //! \return The number of players.
    [[nodiscard]] std::size_t GetNumPlayers() const;

    //! Returns the current player.
    //! \return The current player.
    [[nodiscard]] Player& GetCurrentPlayer();

    //! Returns the player at \p idx.
    //! \param idx The index of player array.
    //! \return The player at \p idx.
    [[nodiscard]] Player& GetPlayer(std::size_t idx);

    //! Starts the game.
    void Start();

    //! Plays round for each player.
    void PlayRound();

    //! Calculates the result.
    void CalculateResult();

    Step step = Step::INVALID;
    Step nextStep = Step::INVALID;

 private:
    GameConfig m_config;
    GameState m_gameState;
};
}  // namespace YahtzeeMaster

#endif