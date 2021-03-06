#include "VulkanInstance.h"

namespace Waffles{
    void VulkanInstance::load(GLFWwindow* window){
        uint32_t extensionCount = 0;
        _windowRef = window;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        LOG("%d", extensionCount);
        DEBUG_FUNC(_createInstance("Waffles-RTX-Engine", "Waffles"));
        DEBUG_FUNC(_createDebugMessenger());
        DEBUG_FUNC(_createSurface());
        DEBUG_FUNC(_setPhysicalDevice());
        DEBUG_FUNC(_createLogicalDevice());
        DEBUG_FUNC(_createSwapChain());
        DEBUG_FUNC(_createImageViews());
        DEBUG_FUNC(_createRenderPass());
        DEBUG_FUNC(_createGraphicsPipeline());
        DEBUG_FUNC(_createFrameBuffers());
        DEBUG_FUNC(_createGraphicsCommandPool());
        DEBUG_FUNC(_createGraphicsCommandPool());
        DEBUG_FUNC(_createVertexBuffers());
        DEBUG_FUNC(_createGraphicsCommandBuffers());
        DEBUG_FUNC(_createSyncObjects());
        
    }


    void VulkanInstance::_createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory){
        VkBufferCreateInfo bufferInfo{};
        bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        bufferInfo.usage = usage;
        bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
        bufferInfo.size = size;

        if (vkCreateBuffer(_logicalDevice, &bufferInfo, nullptr, &buffer) != VK_SUCCESS) {
            ERROR("failed to create vertex buffer!");
        }

        VkMemoryRequirements memRequirements;
        vkGetBufferMemoryRequirements(_logicalDevice, buffer, &memRequirements);
        VkMemoryAllocateInfo allocInfo{};
        allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        allocInfo.allocationSize = memRequirements.size;
        allocInfo.memoryTypeIndex = findMemoryType(memRequirements.memoryTypeBits, properties);
        if (vkAllocateMemory(_logicalDevice, &allocInfo, nullptr, &bufferMemory) != VK_SUCCESS) {
            ERROR("failed to allocate vertex buffer memory!");
        }
        vkBindBufferMemory(_logicalDevice, buffer, bufferMemory, 0);


    }


    void VulkanInstance::_createVertexBuffers(){
        VkDeviceSize bufferSize = sizeof(vertices[0]) * vertices.size();
       
        VkBuffer stagingBuffer;
        VkDeviceMemory stagingBufferMemory;
        _createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);


        

        void* data;
        vkMapMemory(_logicalDevice, stagingBufferMemory, 0, bufferSize, 0, &data);
        memcpy(data, vertices.data(), (size_t) bufferSize);
        vkUnmapMemory(_logicalDevice, stagingBufferMemory);
        
        _createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, _vertexBuffer, _vertexBufferMemory);
        _copyBuffer(stagingBuffer, _vertexBuffer, bufferSize);
        
        vkDestroyBuffer(_logicalDevice, stagingBuffer, nullptr);
        vkFreeMemory(_logicalDevice, stagingBufferMemory, nullptr);

    }

    void VulkanInstance::_copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size){
        VkCommandBufferAllocateInfo allocInfo{};
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandPool = _graphicsCommandPool;
        allocInfo.commandBufferCount = 1;
        VkCommandBuffer commandBuffer;
        vkAllocateCommandBuffers(_logicalDevice, &allocInfo, &commandBuffer);


        VkCommandBufferBeginInfo beginInfo{};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

        vkBeginCommandBuffer(commandBuffer, &beginInfo);

        VkBufferCopy copyRegion{};
        //copyRegion.srcOffset = 0;
        //copyRegion.dstOffset = 0;
        copyRegion.size = size;
        vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, 1, &copyRegion);
        vkEndCommandBuffer(commandBuffer);


        VkSubmitInfo submitInfo{};
        submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submitInfo.commandBufferCount = 1;
        submitInfo.pCommandBuffers = &commandBuffer;

        vkQueueSubmit(_graphicsQueue, 1, &submitInfo, VK_NULL_HANDLE);
        vkQueueWaitIdle(_graphicsQueue);

        vkFreeCommandBuffers(_logicalDevice, _graphicsCommandPool, 1, &commandBuffer);


    }


    void VulkanInstance::_cleanupSwapChain(){
        for (size_t i = 0; i < _swapChainFramebuffers.size(); i++) {
            vkDestroyFramebuffer(_logicalDevice, _swapChainFramebuffers[i], nullptr);
        }

        vkFreeCommandBuffers(_logicalDevice, _graphicsCommandPool, static_cast<uint32_t>(_graphicsCommandBuffers.size()), _graphicsCommandBuffers.data());

        vkDestroyPipeline(_logicalDevice, _graphicsPipeline, nullptr);
        vkDestroyPipelineLayout(_logicalDevice, _pipelineLayout, nullptr);
        vkDestroyRenderPass(_logicalDevice, _renderPass, nullptr);

        for (size_t i = 0; i < _swapChainImageViews.size(); i++) {
            vkDestroyImageView(_logicalDevice, _swapChainImageViews[i], nullptr);
        }

        vkDestroySwapchainKHR(_logicalDevice, _swapChain, nullptr);

    }


    void VulkanInstance::recreateSwapChain(){

        vkDeviceWaitIdle(_logicalDevice);
        _cleanupSwapChain();
        while(WINDOW_WIDTH == 0 || WINDOW_HEIGHT == 0) glfwWaitEvents();
        vkDeviceWaitIdle(_logicalDevice);

        _createSwapChain();
        _createImageViews();
        _createRenderPass();
        _createGraphicsPipeline();
        _createFrameBuffers();
        _createGraphicsCommandBuffers();

    }


    void VulkanInstance::render(){
        vkWaitForFences(_logicalDevice, 1, &_f_inFlightFences[_currentFrame], VK_TRUE, UINT64_MAX);



        uint32_t imageIndex;
        VkResult result = vkAcquireNextImageKHR(_logicalDevice, _swapChain, UINT64_MAX, _s_imagesAvailable[_currentFrame], VK_NULL_HANDLE, &imageIndex);
        if(result == VK_ERROR_OUT_OF_DATE_KHR){
            recreateSwapChain();
        } else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
            ERROR("failed to acquire swap chain image!");
        }
        if(_f_imagesInFlight[imageIndex] != VK_NULL_HANDLE) vkWaitForFences(_logicalDevice, 1, &_f_imagesInFlight[imageIndex], VK_TRUE, UINT64_MAX);
        _f_imagesInFlight[imageIndex] = _f_inFlightFences[_currentFrame];


        VkSubmitInfo submitInfo{};
        submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

        VkSemaphore waitSemaphores[] = {_s_imagesAvailable[_currentFrame]};
        VkSemaphore signalSemaphores[] = {_s_rendersFinished[_currentFrame]};
        VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
        submitInfo.waitSemaphoreCount = 1;
        submitInfo.pWaitSemaphores = waitSemaphores;
        submitInfo.pWaitDstStageMask = waitStages;
        submitInfo.commandBufferCount = 1;
        submitInfo.pCommandBuffers = &_graphicsCommandBuffers[imageIndex];
        submitInfo.signalSemaphoreCount = 1;
        submitInfo.pSignalSemaphores = signalSemaphores;

        vkResetFences(_logicalDevice, 1, &_f_inFlightFences[_currentFrame]);

        if (vkQueueSubmit(_graphicsQueue, 1, &submitInfo, _f_inFlightFences[_currentFrame]) != VK_SUCCESS) {
            ERROR("Failed to submit draw command buffer!");
        }



        VkSubpassDependency dependency{};
        dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
        dependency.dstSubpass = 0;
        dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
        dependency.srcAccessMask = 0;
        dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
        dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;


        VkPresentInfoKHR presentInfo{};
        presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

        presentInfo.waitSemaphoreCount = 1;
        presentInfo.pWaitSemaphores = signalSemaphores;

        VkSwapchainKHR swapChains[] = {_swapChain};
        presentInfo.swapchainCount = 1;
        presentInfo.pSwapchains = swapChains;
        presentInfo.pImageIndices = &imageIndex;
        presentInfo.pResults = nullptr; // Optional

        vkQueuePresentKHR(_presentationQueue, &presentInfo);

        _currentFrame = (_currentFrame+1)% _MAX_FRAMES_IN_FLIGHT;

    }

    void VulkanInstance::_createSyncObjects(){
        _f_inFlightFences.resize(_MAX_FRAMES_IN_FLIGHT);
        _f_imagesInFlight.resize(_swapChainImages.size(), VK_NULL_HANDLE);
        _s_imagesAvailable.resize(_MAX_FRAMES_IN_FLIGHT);
        _s_rendersFinished.resize(_MAX_FRAMES_IN_FLIGHT);
        VkSemaphoreCreateInfo semaphoreInfo{};
        semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
        VkFenceCreateInfo fenceInfo{};
        fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;
        for (size_t i = 0; i < _MAX_FRAMES_IN_FLIGHT; i++){
            if (vkCreateSemaphore(_logicalDevice, &semaphoreInfo, nullptr, &_s_imagesAvailable[i]) != VK_SUCCESS || vkCreateSemaphore(_logicalDevice, &semaphoreInfo, nullptr, &_s_rendersFinished[i]) != VK_SUCCESS) {
                ERROR("Failed to create semaphores at i = '%d'", i);
            }
            if (vkCreateFence(_logicalDevice, &fenceInfo, nullptr, &_f_inFlightFences[i]) != VK_SUCCESS) {
                ERROR("Failed to create fence at i = '%d'", i);
            }
        }


    }
    
    void VulkanInstance::_createGraphicsCommandBuffers(){
        _graphicsCommandBuffers.resize(_swapChainFramebuffers.size());

        VkCommandBufferAllocateInfo allocInfo{};
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;  
        allocInfo.commandPool = _graphicsCommandPool;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandBufferCount = (uint32_t) _graphicsCommandBuffers.size();

        if(vkAllocateCommandBuffers(_logicalDevice, &allocInfo, _graphicsCommandBuffers.data()) != VK_SUCCESS){
            ERROR("Failed to allocate graphics command buffers from graphics command pool");
        }

        //begin recording commands to buffers
        for(size_t i = 0; i < _graphicsCommandBuffers.size(); i++){
            VkCommandBufferBeginInfo info;
            info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
            info.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT; 
            info.pInheritanceInfo = nullptr; 
            info.pNext = nullptr;
            
            if(vkBeginCommandBuffer(_graphicsCommandBuffers[i], &info) != VK_SUCCESS){
                ERROR("Failed to begin recording command buffers");
            }
            VkRenderPassBeginInfo renderPassInfo{};
            renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
            renderPassInfo.renderPass = _renderPass;
            renderPassInfo.framebuffer = _swapChainFramebuffers[i];
            renderPassInfo.renderArea.offset = {0, 0};
            renderPassInfo.renderArea.extent = _swapChainExtent;
            renderPassInfo.clearValueCount = VK_ATTACHMENT_LOAD_OP_CLEAR;
            renderPassInfo.pClearValues = &_clearColor;

            vkCmdBeginRenderPass(_graphicsCommandBuffers[i], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);
            vkCmdBindPipeline(_graphicsCommandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, _graphicsPipeline); //VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR
            VkBuffer vertexBuffers[] = {_vertexBuffer};
            VkDeviceSize offsets[] = {0};
            vkCmdBindVertexBuffers(_graphicsCommandBuffers[i], 0, 1, vertexBuffers, offsets);
            vkCmdDraw(_graphicsCommandBuffers[i], 6, 1, 0, 0);

            vkCmdEndRenderPass(_graphicsCommandBuffers[i]);
            if(vkEndCommandBuffer(_graphicsCommandBuffers[i]) != VK_SUCCESS){
                ERROR("Failed to record to command buffer");
            }

        }

    }

    void VulkanInstance::_createGraphicsCommandPool(){
        QueueFamilyIndices queueFamilyIndices = _getQueueFamilies(_physicalDevice);

        VkCommandPoolCreateInfo poolInfo{};
        poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        poolInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily.index;

        if((vkCreateCommandPool(_logicalDevice, &poolInfo, nullptr, &_graphicsCommandPool)) != VK_SUCCESS){
            ERROR("Failed to create graphics command pool");
        }
    }
    void VulkanInstance::_createFrameBuffers(){
        _swapChainFramebuffers.resize(_swapChainImageViews.size());

        for (size_t i = 0; i < _swapChainImageViews.size(); i++) {
            VkImageView attachments[] = {
                _swapChainImageViews[i]
            };

            VkFramebufferCreateInfo framebufferInfo{};
            framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
            framebufferInfo.renderPass = _renderPass;
            framebufferInfo.attachmentCount = 1;
            framebufferInfo.pAttachments = attachments;
            framebufferInfo.width = _swapChainExtent.width;
            framebufferInfo.height = _swapChainExtent.height;
            framebufferInfo.layers = 1;

            if (vkCreateFramebuffer(_logicalDevice, &framebufferInfo, nullptr, &_swapChainFramebuffers[i]) != VK_SUCCESS) {
                ERROR("failed to create framebuffer!");
            }
        }

    }
    void VulkanInstance::_createRenderPass(){
        VkAttachmentDescription colorAttachment{};
        colorAttachment.format = _swapChainImageFormat;
        colorAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
        
        colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
        colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
        colorAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
        colorAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        colorAttachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

        VkAttachmentReference colorAttachmentRef{};
        colorAttachmentRef.attachment = 0;
        colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

        VkSubpassDescription subpass{};
        subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
        subpass.colorAttachmentCount = 1;
        subpass.pColorAttachments = &colorAttachmentRef; 


        VkRenderPassCreateInfo renderPassInfo{};
        renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
        renderPassInfo.attachmentCount = 1;
        renderPassInfo.pAttachments = &colorAttachment;
        renderPassInfo.subpassCount = 1;
        renderPassInfo.pSubpasses = &subpass;

        if (vkCreateRenderPass(_logicalDevice, &renderPassInfo, nullptr, &_renderPass) != VK_SUCCESS) {
            ERROR("failed to create render pass!");
        }  

    }

    void VulkanInstance::_createGraphicsPipeline(){
        auto vertShaderCode = Waffles::FileLoader::readFile(WAFFLES_INTERNAL_SHADER_SPIRV("passthrough_vert.spv"));
        auto fragShaderCode = Waffles::FileLoader::readFile(WAFFLES_INTERNAL_SHADER_SPIRV("RayMarching_frag.spv"));

        VkShaderModule vertShaderModule = _createShaderModule(vertShaderCode);
        VkShaderModule fragShaderModule = _createShaderModule(fragShaderCode);


        VkPipelineShaderStageCreateInfo vertShaderStageInfo{};
        vertShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
        vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
        vertShaderStageInfo.module = vertShaderModule;
        vertShaderStageInfo.pName = "main";

        VkPipelineShaderStageCreateInfo fragShaderStageInfo{};
        fragShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
        fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
        fragShaderStageInfo.module = fragShaderModule;
        fragShaderStageInfo.pName = "main";

        VkPipelineShaderStageCreateInfo shaderStages[] = {vertShaderStageInfo, fragShaderStageInfo};


        auto bindingDescription = Vertex_Tmp::getBindingDescription();
        auto attributeDescriptions = Vertex_Tmp::getAttributeDescriptions();

        VkPipelineVertexInputStateCreateInfo vertexInputInfo{};
        vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
        vertexInputInfo.vertexBindingDescriptionCount = 1;
        vertexInputInfo.vertexAttributeDescriptionCount = (uint32_t)(attributeDescriptions.size());
        vertexInputInfo.pVertexBindingDescriptions = &bindingDescription; 
        vertexInputInfo.pVertexAttributeDescriptions = attributeDescriptions.data(); 

        VkPipelineInputAssemblyStateCreateInfo inputAssembly{};
        inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
        inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
        inputAssembly.primitiveRestartEnable = VK_FALSE;

        VkViewport viewport{};
        viewport.x = 0.0f;
        viewport.y = 0.0f;
        viewport.width = (float) _swapChainExtent.width;
        viewport.height = (float) _swapChainExtent.height;
        viewport.minDepth = 0.0f;
        viewport.maxDepth = 1.0f;

        VkRect2D scissor{};
        scissor.offset = {0, 0};
        scissor.extent = _swapChainExtent;


        VkPipelineViewportStateCreateInfo viewportState{};
        viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
        viewportState.viewportCount = 1;
        viewportState.pViewports = &viewport;
        viewportState.scissorCount = 1;
        viewportState.pScissors = &scissor;

        VkPipelineRasterizationStateCreateInfo rasterizer{};
        rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
        rasterizer.depthClampEnable = VK_FALSE;
        rasterizer.rasterizerDiscardEnable = VK_FALSE;
        rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
        rasterizer.lineWidth = 1.0f;

        rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
        rasterizer.frontFace = VK_FRONT_FACE_CLOCKWISE;

        rasterizer.depthBiasEnable = VK_FALSE;
        rasterizer.depthBiasConstantFactor = 0.0f; // Optional
        rasterizer.depthBiasClamp = 0.0f; // Optional
        rasterizer.depthBiasSlopeFactor = 0.0f; // Optional

        VkPipelineMultisampleStateCreateInfo multisampling{};
        multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
        multisampling.sampleShadingEnable = VK_FALSE;
        multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
        multisampling.minSampleShading = 1.0f; // Optional
        multisampling.pSampleMask = nullptr; // Optional
        multisampling.alphaToCoverageEnable = VK_FALSE; // Optional
        multisampling.alphaToOneEnable = VK_FALSE; // Optional


        VkPipelineColorBlendAttachmentState colorBlendAttachment{};
        colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
        colorBlendAttachment.blendEnable = VK_FALSE;
        colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_ONE; // Optional
        colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
        colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD; // Optional
        colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE; // Optional
        colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
        colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD; // Optional

        VkPipelineColorBlendStateCreateInfo colorBlending{};
        colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
        colorBlending.logicOpEnable = VK_FALSE;
        colorBlending.logicOp = VK_LOGIC_OP_COPY; // Optional
        colorBlending.attachmentCount = 1;
        colorBlending.pAttachments = &colorBlendAttachment;
        colorBlending.blendConstants[0] = 0.0f; // Optional
        colorBlending.blendConstants[1] = 0.0f; // Optional
        colorBlending.blendConstants[2] = 0.0f; // Optional
        colorBlending.blendConstants[3] = 0.0f; // Optional


        //for runtime pipeline features
        VkDynamicState dynamicStates[] = {
            VK_DYNAMIC_STATE_VIEWPORT,
            VK_DYNAMIC_STATE_LINE_WIDTH
        };

        VkPipelineDynamicStateCreateInfo dynamicState{};
        dynamicState.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
        dynamicState.dynamicStateCount = 2;
        dynamicState.pDynamicStates = dynamicStates;




        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = 0; // Optional
        pipelineLayoutInfo.pSetLayouts = nullptr; // Optional
        pipelineLayoutInfo.pushConstantRangeCount = 0; // Optional
        pipelineLayoutInfo.pPushConstantRanges = nullptr; // Optional

        if (vkCreatePipelineLayout(_logicalDevice, &pipelineLayoutInfo, nullptr, &_pipelineLayout) != VK_SUCCESS) {
            ERROR("failed to create pipeline layout!");
        }


        VkGraphicsPipelineCreateInfo pipelineInfo{};
        pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
        pipelineInfo.stageCount = 2;
        pipelineInfo.pStages = shaderStages;
        pipelineInfo.pVertexInputState = &vertexInputInfo;
        pipelineInfo.pInputAssemblyState = &inputAssembly;
        pipelineInfo.pViewportState = &viewportState;
        pipelineInfo.pRasterizationState = &rasterizer;
        pipelineInfo.pMultisampleState = &multisampling;
        pipelineInfo.pDepthStencilState = nullptr; // Optional
        pipelineInfo.pColorBlendState = &colorBlending;
        pipelineInfo.pDynamicState = nullptr; // Optional
        pipelineInfo.layout = _pipelineLayout;
        pipelineInfo.renderPass = _renderPass;
        pipelineInfo.subpass = 0;
        pipelineInfo.basePipelineHandle = VK_NULL_HANDLE; // Optional
        pipelineInfo.basePipelineIndex = -1; // Optional        

        if (vkCreateGraphicsPipelines(_logicalDevice, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &_graphicsPipeline) != VK_SUCCESS) {
            ERROR("failed to create graphics pipeline!");
        }

        vkDestroyShaderModule(_logicalDevice, vertShaderModule, nullptr);
        vkDestroyShaderModule(_logicalDevice, fragShaderModule, nullptr);
    }

    //wraps the code in a vkshadermodule object before being passed to the pipeline
    //'code' is the bytecode representation of the glsl code - spirv 
    VkShaderModule VulkanInstance::_createShaderModule(const std::vector<char>& code){
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
        VkShaderModule shaderModule;
        if (vkCreateShaderModule(_logicalDevice, &createInfo, nullptr, &shaderModule) != VK_SUCCESS) {
            ERROR("failed to create shader module!");
        }
        return shaderModule;
    }

    void VulkanInstance::_createInstance(const char* appName, const char* engineName){
        if(enableValidationLayers && !_validatationLayersAssert()){
            ERROR("Validation layers requested but are not availble -- Debug mode is off or validation layer couldn't be found");
        }

        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = appName;
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = engineName;
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;


        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        auto extensions = getRequiredExtensions();
        createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
        createInfo.ppEnabledExtensionNames = extensions.data();

        VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo;
        if (enableValidationLayers) {
            LOG("Enabled validation layers: size: %d", static_cast<uint32_t>(_validationLayers.size()));
            createInfo.enabledLayerCount = static_cast<uint32_t>(_validationLayers.size());
            createInfo.ppEnabledLayerNames = _validationLayers.data();

            populateDebugMessengerCreateInfo(debugCreateInfo);
            createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*) &debugCreateInfo;
        } else {
            createInfo.enabledLayerCount = 0;
            createInfo.pNext = nullptr;
        }
        VkResult result = vkCreateInstance(&createInfo, nullptr, &_vulkanInstance);
        if (result != VK_SUCCESS) {
            ERROR("Failed to create vulkan instance : %d - %d, %d, %d", result, VK_ERROR_LAYER_NOT_PRESENT, VK_SUCCESS, VK_INCOMPLETE);
        }else{
            DEBUG("Vulkan Instance Created!");
        }
    }


    //where we check if the extensions are supported for a device
    bool VulkanInstance::_deviceSupportsExtensions(VkPhysicalDevice device){
        uint32_t extensionCount;
        vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, nullptr);
        std::vector<VkExtensionProperties> availableExtensions(extensionCount);
        vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, availableExtensions.data());

        std::set<std::string> requiredExtensions(_deviceExtensions.begin(), _deviceExtensions.end());

        for (const auto& extension : availableExtensions) {
            //LOG("Extension: '%s'", extension.extensionName);
            requiredExtensions.erase(extension.extensionName);
        }
        return requiredExtensions.empty();
    }

    SwapChainSupportDetails VulkanInstance::_querySwapChainSupport(VkPhysicalDevice device){
        SwapChainSupportDetails details;
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, _surface, &details.capabilities);

        uint32_t formatCount;
        vkGetPhysicalDeviceSurfaceFormatsKHR(device, _surface, &formatCount, nullptr);

        if (formatCount != 0) {
            details.formats.resize(formatCount);
            vkGetPhysicalDeviceSurfaceFormatsKHR(device, _surface, &formatCount, details.formats.data());
        }

        uint32_t presentModeCount;
        vkGetPhysicalDeviceSurfacePresentModesKHR(device, _surface, &presentModeCount, nullptr);

        if (presentModeCount != 0) {
            details.presentModes.resize(presentModeCount);
            vkGetPhysicalDeviceSurfacePresentModesKHR(device, _surface, &presentModeCount, details.presentModes.data());
        }



        return details;

    }



    void VulkanInstance::_createDebugMessenger() {
        if (!enableValidationLayers){
            WARN("NO validation layers enabled");
            return;
        }

        VkDebugUtilsMessengerCreateInfoEXT createInfo;
        populateDebugMessengerCreateInfo(createInfo);

        if (CreateDebugUtilsMessengerEXT(_vulkanInstance, &createInfo, nullptr, &_debugMessenger) != VK_SUCCESS) {
            ERROR("failed to set up debug messenger!");
        }else{
            LOG("Debug Messenger successfully created.");
        }
    }

    void VulkanInstance::_createImageViews(){
        _swapChainImageViews.resize(_swapChainImages.size());

        for (size_t i = 0; i < _swapChainImages.size(); i++) {
            VkImageViewCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
            createInfo.image = _swapChainImages[i];
            createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
            createInfo.format = _swapChainImageFormat; //VK_FORMAT_B8G8R8A8_SRGB
            createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
            createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
            createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
            createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
            createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            createInfo.subresourceRange.baseMipLevel = 0;
            createInfo.subresourceRange.levelCount = 1;
            createInfo.subresourceRange.baseArrayLayer = 0;
            createInfo.subresourceRange.layerCount = 1;
            if (vkCreateImageView(_logicalDevice, &createInfo, nullptr, &_swapChainImageViews[i]) != VK_SUCCESS) {
                ERROR("failed to create image views!");
            }

        }   
    }


    bool VulkanInstance::_isRTXEnabledGPU(VkPhysicalDevice dev){
        VkPhysicalDeviceProperties deviceProperties;
        VkPhysicalDeviceFeatures deviceFeatures;
        vkGetPhysicalDeviceProperties(dev, &deviceProperties);
        vkGetPhysicalDeviceFeatures(dev, &deviceFeatures);
        LOG("Testing: %s", deviceProperties.deviceName );

        QueueFamilyIndices indices = _getQueueFamilies(dev);

        bool extensionsSupported = _deviceSupportsExtensions(dev);
        if(extensionsSupported){
            LOG("Device supports RTX");
        }

        bool swapChainAdequate = false;
        if (extensionsSupported) {
            SwapChainSupportDetails swapChainSupport = _querySwapChainSupport(dev);
            swapChainAdequate = !swapChainSupport.formats.empty() && !swapChainSupport.presentModes.empty();
            if(swapChainAdequate){
                LOG("Swap chain adequate");
            }else{
                WARN("Swap chain inadequate");
            }
        }

        return indices.isComplete() && extensionsSupported && swapChainAdequate;
    }



    void VulkanInstance::_setPhysicalDevice(){
        VkPhysicalDevice physDev = VK_NULL_HANDLE;
        uint32_t devCount = 0;
        vkEnumeratePhysicalDevices(_vulkanInstance, &devCount, nullptr);
        LOG("Num devices: %d", devCount);
        if(devCount == 0){
            ERROR("No GPUs found ");
        }
        std::vector<VkPhysicalDevice> devices(devCount);
        vkEnumeratePhysicalDevices(_vulkanInstance, &devCount, devices.data());

        for (const auto& device : devices) {
            if (_isRTXEnabledGPU(device)) {
                _physicalDevice = device;
                LOG("RTX Enabled device set");
                //break;
            }
        }

        if (_physicalDevice == VK_NULL_HANDLE) {
            ERROR("No RTX Enabled GPU support found.");
        }
        
    }

    QueueFamilyIndices VulkanInstance::_getQueueFamilies(VkPhysicalDevice device){
        QueueFamilyIndices indices;
        uint32_t queueFamilyCount = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

        std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());
        
        
        int i = 0;
        for (const auto& queueFamily : queueFamilies) {
            DEBUG("Device allows: %d of these flags: %s", queueFamily.queueCount, queueFamilyBitToString(queueFamily.queueFlags).c_str());
            if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT){
                indices.graphicsFamily.index = i;
                indices.graphicsFamily.set = true;
            }
            VkBool32 presentSupport = true;
            vkGetPhysicalDeviceSurfaceSupportKHR(device, i, _surface, &presentSupport);
            if (presentSupport) {
                indices.presentationFamily.index = i;
                indices.presentationFamily.set = true;
            }
            if(indices.isComplete()) break;
            i++;

        }
        return indices;
    }

    void VulkanInstance::_createSwapChain(){
        SwapChainSupportDetails swapChainSupport = _querySwapChainSupport(_physicalDevice);

        VkSurfaceFormatKHR surfaceFormat = _chooseSwapSurfaceFormat(swapChainSupport.formats);
        VkPresentModeKHR presentMode = _chooseSwapPresentMode(swapChainSupport.presentModes);
        VkExtent2D extent = _chooseSwapExtent(swapChainSupport.capabilities);

        uint32_t imageCount = swapChainSupport.capabilities.minImageCount + 1;
        LOG("Swap chain contains %d images", imageCount);
        if (swapChainSupport.capabilities.maxImageCount > 0 && imageCount > swapChainSupport.capabilities.maxImageCount) {
            imageCount = swapChainSupport.capabilities.maxImageCount;
            LOG("Swap chain adjusted to %d images", imageCount);
        }

        VkSwapchainCreateInfoKHR createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
        createInfo.surface = _surface;
        createInfo.minImageCount = imageCount;
        createInfo.imageFormat = surfaceFormat.format;
        createInfo.imageColorSpace = surfaceFormat.colorSpace;
        createInfo.imageExtent = extent;
        createInfo.imageArrayLayers = 1;
        createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

        QueueFamilyIndices indices = _getQueueFamilies(_physicalDevice);
        uint32_t queueFamilyIndices[] = {indices.graphicsFamily.index, indices.presentationFamily.index};

        if (indices.graphicsFamily.index != indices.presentationFamily.index) {
            createInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
            createInfo.queueFamilyIndexCount = 2;
            createInfo.pQueueFamilyIndices = queueFamilyIndices;
        } else {
            createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
        }
        createInfo.preTransform = swapChainSupport.capabilities.currentTransform;
        createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR; //specifies if the alpha channel should be used for blending with other windows
        createInfo.presentMode = presentMode;
        createInfo.clipped = VK_TRUE;
        createInfo.oldSwapchain = VK_NULL_HANDLE;

        if (vkCreateSwapchainKHR(_logicalDevice, &createInfo, nullptr, &_swapChain) != VK_SUCCESS) {
            ERROR("failed to create swap chain!");
        }
        vkGetSwapchainImagesKHR(_logicalDevice, _swapChain, &imageCount, nullptr);
        _swapChainImages.resize(imageCount);
        vkGetSwapchainImagesKHR(_logicalDevice, _swapChain, &imageCount, _swapChainImages.data());
        _swapChainExtent = extent;
        _swapChainImageFormat = surfaceFormat.format;

    }


    VkSurfaceFormatKHR  VulkanInstance::_chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats){
        for (const auto& availableFormat : availableFormats) {
            if (availableFormat.format == VK_FORMAT_B8G8R8A8_SRGB && availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
                LOG("Found optimal swap surface format");
                return availableFormat;
            }
        }
        LOG("Defaulting to any swap surface format");
        return availableFormats[0];
    }


    VkPresentModeKHR VulkanInstance::_chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes){
        #ifdef DEBUG_MODE
            int mode = 0;
            for (const auto& availablePresentMode : availablePresentModes) mode += availablePresentMode;
            
            DEBUG("Swapchain presentation mode allows: %s", presentModeBitToString(mode).c_str());
        #endif
        for (const auto& availablePresentMode : availablePresentModes) {
            if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR) {
                return availablePresentMode;
            }
        }

            return VK_PRESENT_MODE_FIFO_KHR;
    }

    VkExtent2D VulkanInstance::_chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities){
        if (capabilities.currentExtent.width != UINT32_MAX) {
            return capabilities.currentExtent;
        } else {
            int width, height;
            glfwGetFramebufferSize(_windowRef, &width, &height);
            DEBUG("(%d, %d)", width, height);
            VkExtent2D actualExtent = {
                static_cast<uint32_t>(width),
                static_cast<uint32_t>(height)
            };

            actualExtent.width = std::max(capabilities.minImageExtent.width, std::min(capabilities.maxImageExtent.width, actualExtent.width));
            actualExtent.height = std::max(capabilities.minImageExtent.height, std::min(capabilities.maxImageExtent.height, actualExtent.height));

            return actualExtent;
        }
    }



    void VulkanInstance::_createLogicalDevice(){
        QueueFamilyIndices indices = _getQueueFamilies(_physicalDevice);
        
        std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
        std::set<uint32_t> uniqueQueueFamilies = {indices.graphicsFamily.index, indices.presentationFamily.index};

        float queuePriority = 1.0f;
        for (uint32_t queueFamily : uniqueQueueFamilies) {
            VkDeviceQueueCreateInfo queueCreateInfo{};
            queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            queueCreateInfo.queueFamilyIndex = queueFamily;
            queueCreateInfo.queueCount = 1;
            queueCreateInfo.pQueuePriorities = &queuePriority;
            queueCreateInfos.push_back(queueCreateInfo);
        }

        VkPhysicalDeviceFeatures deviceFeatures{};
        VkDeviceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

        createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
        createInfo.pQueueCreateInfos = queueCreateInfos.data();

        createInfo.pEnabledFeatures = &deviceFeatures;

        createInfo.ppEnabledExtensionNames = _deviceExtensions.data();   
        createInfo.enabledExtensionCount = static_cast<uint32_t>(_deviceExtensions.size());
        if(enableValidationLayers){
            createInfo.enabledLayerCount = static_cast<uint32_t>(_validationLayers.size());
            createInfo.ppEnabledLayerNames = _validationLayers.data();
        }else createInfo.enabledLayerCount = 0;

        if (vkCreateDevice(_physicalDevice, &createInfo, nullptr, &_logicalDevice) != VK_SUCCESS) {
            ERROR("failed to create logical device!");
        }else {LOG("Created logical device.");}

        vkGetDeviceQueue(_logicalDevice, indices.graphicsFamily.index, 0, &_graphicsQueue); //retrieve queue handle
        vkGetDeviceQueue(_logicalDevice, indices.presentationFamily.index, 0, &_presentationQueue); //retrieve present handle


    }

    void VulkanInstance::_createSurface(){
        if (glfwCreateWindowSurface(_vulkanInstance, _windowRef, nullptr, &_surface) != VK_SUCCESS) {
            ERROR("failed to create window surface!");
        }
    }


    bool VulkanInstance::_validatationLayersAssert(){
        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
        LOG("Validation layers size: %d", layerCount);
        for (const char* layerName : _validationLayers) {
            bool layerFound = false;

            for (const auto& layerProperties : availableLayers) {
                LOG("Checking if %s == %s", layerName, layerProperties.layerName);
                if (strcmp(layerName, layerProperties.layerName) == 0) {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound) {
                return false;
            }
        }
        return true;
    }
    void VulkanInstance::unload(){
        UNLOAD_LOG("Unloading VulkanInstance...");
        _cleanupSwapChain();
        vkDestroyBuffer(_logicalDevice,_vertexBuffer, nullptr);
        vkFreeMemory(_logicalDevice, _vertexBufferMemory, nullptr);
        vkDeviceWaitIdle(_logicalDevice);//wait for queue operations to finish for _logicalDevice
        for (size_t i = 0; i < _MAX_FRAMES_IN_FLIGHT; i++) {
            vkDestroySemaphore(_logicalDevice, _s_imagesAvailable[i], nullptr);
            vkDestroySemaphore(_logicalDevice, _s_rendersFinished[i], nullptr);
            vkDestroyFence(_logicalDevice, _f_inFlightFences[i], nullptr);
            
        }
        
        if(enableValidationLayers) DestroyDebugUtilsMessengerEXT(_vulkanInstance, _debugMessenger, nullptr);
        vkDestroySurfaceKHR(_vulkanInstance, _surface, nullptr);
        vkDestroyDevice(_logicalDevice, nullptr);
        vkDestroyInstance(_vulkanInstance, nullptr);
        

    }
}