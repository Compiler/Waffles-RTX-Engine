if not exist "build" mkdir build
cd build
cmake -G "MinGW Makefiles" ..
make