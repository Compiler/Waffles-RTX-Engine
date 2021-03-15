#include "FileLoader.h"

namespace Waffles{

    std::vector<char> FileLoader::readFile(const char* fileName){
        std::ifstream file(fileName, std::ios::ate | std::ios::binary);
        if(!file.is_open()){ERROR("Couldn't open file '%s'", fileName);}
        size_t fileSize = (size_t) file.tellg();
        std::vector<char> buffer(fileSize);
        file.seekg(0);
        file.read(buffer.data(), fileSize);
        file.close();

        return buffer;

    }

}