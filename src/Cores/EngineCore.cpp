#include "EngineCore.h"

namespace Waffles{


    void EngineCore::load(){
        DEBUG("EngineCore Loading...");
        const char* appName = "Waffles-RTX-PBR";
        _window = new Waffles::Window(720, 720.0 / (16.0 / 9.0), appName);

       _vulkanInstance = Startup::createVKInstance("Waffles-RTX-PBR", "Waffles");
       _validatationLayersAssert();
       _setPhysicalDevice();
    }

    void EngineCore::_validatationLayersAssert(){
        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
        bool validationLayersSupported = false;
        const std::vector<const char*> _validationLayers = {"VK_LAYER_KHRONOS_validation"};
        for (const char* layerName : _validationLayers) {
            bool layerFound = false;

            for (const auto& layerProperties : availableLayers) {
                if (strcmp(layerName, layerProperties.layerName) == 0) {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound) {
                validationLayersSupported = false;
            }
        }

        validationLayersSupported = true;

        #ifdef DEBUG_MODE
            if(!validationLayersSupported){
                ERROR("Debug mode activated but couldn't initialize validation layers");
            }
        #else
            DEBUG("Validation layers initialized");
        #endif


    }


    void EngineCore::_setPhysicalDevice(){
        VkPhysicalDevice physDev = VK_NULL_HANDLE;
        uint32_t devCount = 0;
        vkEnumeratePhysicalDevices(_vulkanInstance, &devCount, nullptr);
        
    }


    void EngineCore::update(){

    }

    void EngineCore::render(){


    }

    void EngineCore::unload(){
        WARN("Unloading EngineCore...");

        vkDestroyInstance(_vulkanInstance, nullptr);

        _window->destroy();
        delete(_window);
        glfwTerminate();

    }



}