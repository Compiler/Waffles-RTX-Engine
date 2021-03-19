#include "VkDebugUtils.h"
namespace Waffles{
    std::string queueFamilyBitToString(int value){
        std::string stringVersion = "{";
        int c = 0;
        if((value & ( 1 << c )) >> c++ == 1){
            stringVersion += " GRAPHICS ";
        }
        if((value & ( 1 << c )) >> c++ == 1){
            stringVersion += " COMPUTE ";
        }
        if((value & ( 1 << c )) >> c++ == 1){
            stringVersion += " TRANSFER ";
        }
        if((value & ( 1 << c )) >> c++ == 1){
            stringVersion += " SPARSE ";
        }
        if((value & ( 1 << c )) >> c++ == 1){
            stringVersion += " PROTECTED ";
        }


        return stringVersion + "}";
    }

    std::string presentModeBitToString(int value){
        // VK_PRESENT_MODE_IMMEDIATE_KHR = 0,
        // VK_PRESENT_MODE_MAILBOX_KHR = 1,
        // VK_PRESENT_MODE_FIFO_KHR = 2,
        // VK_PRESENT_MODE_FIFO_RELAXED_KHR = 3,
        // VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR = 1000111000,
        // VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR = 1000111001,
        std::string stringVersion = "{";
        int c = 0;
        if((value & ( 1 << c )) >> c++ == 1){
            stringVersion += " IMMEDIATE ";
        }
        if((value & ( 1 << c )) >> c++ == 1){
            stringVersion += " MAILBOX ";
        }
        if((value & ( 1 << c )) >> c++ == 1){
            stringVersion += " FIFO ";
        }
        if((value & ( 1 << c )) >> c++ == 1){
            stringVersion += " FIFO_RELAXED ";
        }
        if((value & ( 1 << c )) >> c++ == 1){
            stringVersion += " SHARED_DEMAND_REFRESH ";
        }
        if((value & ( 1 << c )) >> c++ == 1){
            stringVersion += " SHARED_CONTINUOUS_REFRESH ";
        }


        return stringVersion + "}";
    }


}
