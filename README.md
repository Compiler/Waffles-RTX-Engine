# Vulkan Ray Tracing

## How to use:

### Window + MinGW64

  - Under Waffles-RTX-Engine, there is a CMakeLists.txt-- open it and change VULKAN_ROOT to point to your vulkan sdk path:

      - i.e. C:/VulkanSDK/1.2.xxx.x/

  - Then, make a folder under Waffles-RTX-Engine named build, cd into it and run 

```
> cmake -G "MinGW Makefiles" ..
> make
> ./WafflesDriver.exe
```


