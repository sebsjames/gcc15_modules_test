// A file that is #included test1.cppm, but itself imports a module
#pragma once

#include <cstdint>
#include <vector>
#include <iostream>
#include <cstring>
#include <memory>

import mplot.tools;

namespace unused
{
    uint32_t a_function()
    {
        if (mplot::tools::fileExists ("some_file")) { return 1; }
        return 0;
    }
}
