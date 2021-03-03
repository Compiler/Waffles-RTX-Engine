#pragma once
#ifdef DEBUG_MODE
constexpr bool __DEBUG_MODE = true;
#elif RELEASE_MODE
constexpr bool __DEBUG_MODE = false;
#endif

#define WAFFLES_ASSERT(x) 

