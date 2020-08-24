// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <YahtzeeMaster/Models/Dice.hpp>

#include <effolkronium/random.hpp>

namespace YahtzeeMaster
{
void Dice::Roll()
{
    using Random = effolkronium::random_static;

    m_value = Random::get<int>(1, 6);
}

}  // namespace YahtzeeMaster