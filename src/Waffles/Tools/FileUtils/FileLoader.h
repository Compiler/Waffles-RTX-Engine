#pragma once
#include <Waffles/Waffles.h>
#include <Waffles/Tools/Logging.h>
#include <vector>
#include <fstream>

namespace Waffles{

    class FileLoader{


        public:
            FileLoader() = delete;
            FileLoader(const FileLoader&) = delete;
            FileLoader operator=(const FileLoader&) = delete;

            static std::vector<char> readFile(const char* fileName);
    };

}