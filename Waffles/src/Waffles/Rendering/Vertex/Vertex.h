#pragma once
#include <Waffles/Waffles.h>
#include <glm/glm.hpp>
#include <vulkan/vulkan.h>
namespace Waffles{

    struct Vertex4f4f{  
        glm::vec4 position;
        glm::vec4 color;

        static VkVertexInputBindingDescription getBindingDescription(){
            VkVertexInputBindingDescription bindingInfo{};

            bindingInfo.binding = 0;
            bindingInfo.stride = sizeof(Vertex4f4f);
            bindingInfo.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;


        }

    };


    template<typename ... T>
    struct GeneralVertex{};

    template<typename T, typename ... Recurse>
    struct GeneralVertex<T, Recurse ...>{
        GeneralVertex(const T& element, const Recurse& ... recurse): element(element), recurse(recurse...){}
        T element;
        GeneralVertex<Recurse ... > recurse;
    };

}