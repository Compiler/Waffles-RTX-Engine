#pragma once
#include <Waffles/Waffles.h>
#include <Waffles/Tools/Logging.h>
#include <vector>
#include <fstream>


// We go back because this is from the binary directory, so we leave build and enter Waffles
#define WAFFLES_INTERNAL(x)         "../Waffles/Resources/" x
#define WAFFLES_INTERNAL_SHADER(x)  WAFFLES_INTERNAL("Shaders/") x
#define WAFFLES_INTERNAL_SHADER_SPIRV(x)  WAFFLES_INTERNAL("Shader_SPIRV/") x
#define WAFFLES_INTERNAL_TEXTURE(x) WAFFLES_INTERNAL("Textures/") x
#define WAFFLES_INTERNAL_MODEL(x)   WAFFLES_INTERNAL("Models/") x
#define WAFFLES_INTERNAL_SOUNDS(x)  WAFFLES_INTERNAL("Sounds/") x
namespace Waffles{

    class FileLoader{


        public:
            FileLoader() = delete;
            FileLoader(const FileLoader&) = delete;
            FileLoader operator=(const FileLoader&) = delete;

            static std::vector<char> readFile(const char* fileName);
    };

}