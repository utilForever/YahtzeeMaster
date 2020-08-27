// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <YahtzeeMaster/Models/Player.hpp>

namespace YahtzeeMaster
{
void Player::Initialize()
{
    m_numReroll = 0;
}

std::array<int, NUM_DICES> Player::GetDiceValues() const
{
    std::array<int, 5> ret{};

    for (std::size_t i = 0; i < ret.size(); ++i)
    {
        ret[i] = m_dices[i].GetValue();
    }

    return ret;
}

void Player::RollDices()
{
    for (auto& dice : m_dices)
    {
        dice.Roll();
    }

    ++m_numReroll;
}
}  // namespace YahtzeeMaster