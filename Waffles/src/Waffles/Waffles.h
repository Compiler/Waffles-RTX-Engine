#pragma once
#ifdef DEBUG_MODE
constexpr bool __DEBUG_MODE = true;
#else
constexpr bool __DEBUG_MODE = false;
#endif

#define WAFFLES_ASSERT(x) 

