// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>

int main()
{
    doctest::Context context;

    // Run queries, or run tests unless --no-run is specified
    const int res = context.run();

    return res;
}