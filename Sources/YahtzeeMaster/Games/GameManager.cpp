// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <YahtzeeMaster/Games/GameManager.hpp>

namespace YahtzeeMaster
{
void GameManager::ProcessNextStep(Game& game, Step step)
{
    switch (step)
    {
        case Step::PLAY_ROUND:
            game.step = step;
            game.PlayRound();
            break;
        case Step::COMPLETE:
            game.step = step;
            break;
        default:
            break;
    }
}
}  // namespace YahtzeeMaster
