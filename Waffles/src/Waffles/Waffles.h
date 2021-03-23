#pragma once
#include <Waffles/Tools/Logging.h>
#ifdef DEBUG_MODE
constexpr bool __DEBUG_MODE = true;
#else
constexpr bool __DEBUG_MODE = false;
#endif
namespace Waffles{
    extern int WINDOW_WIDTH;
    extern int WINDOW_HEIGHT;
}

#define WAFFLES_ASSERT(x) 

