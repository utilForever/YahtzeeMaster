// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <YahtzeeMaster/Games/Game.hpp>

namespace YahtzeeMaster
{
GameState& Game::GetGameState()
{
    return m_gameState;
}
}  // namespace YahtzeeMaster