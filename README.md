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

Here is in theory the entire load you can write, but you need to have the correct sdk version:

```
> git clone https://github.com/Compiler/Waffles-RTX-Engine.git
> cd Waffles-RTX-Engine
> mkdir build
> cd build
HERE IS WHERE YOU WOULD STOP AND CHANGE THE VULKAN SDK VERSION TO YOURS in Waffles-RTX-Engine/CMakeLists.txt
> cmake -G "MinGW Makefiles" ..
> make
> ./WafflesDriver.exe
```
