#pragma once
#include <Waffles/Waffles.h>
#include <glm/glm.hpp>
#include <vulkan/vulkan.h>
#include <array>
namespace Waffles{

    struct Vertex_Tmp{  
        glm::vec4 position;
        glm::vec4 color;

        static VkVertexInputBindingDescription getBindingDescription(){
            VkVertexInputBindingDescription bindingInfo{};

            bindingInfo.binding = 0;
            bindingInfo.stride = sizeof(Vertex_Tmp);
            bindingInfo.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

            return bindingInfo;

        }


        static std::array<VkVertexInputAttributeDescription, 2> getAttributeDescriptions() {
            std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions{};

            attributeDescriptions[0].binding = 0;
            attributeDescriptions[0].location = 0;
            attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
            attributeDescriptions[0].offset = offsetof(Vertex_Tmp, position);//((::size_t)&reinterpret_cast<char const volatile&>((((Vertex_Tmp*)0)->position)));

            attributeDescriptions[1].binding = 0;
            attributeDescriptions[1].location = 1;
            attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
            attributeDescriptions[1].offset = offsetof(Vertex_Tmp, color);//((::size_t)&reinterpret_cast<char const volatile&>((((Vertex_Tmp*)0)->color)));

            return attributeDescriptions;
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