# go-fastdds

Golang connector for eProsima Fast DDS

## Installation

### Eprosima middleware

- CMake 3.14 or higher is required

> sudo apt remove cmake
> sudo apt update
> sudo apt-get install cmake

- Install eProsima Fast DDS binary for linux

> <https://www.eprosima.com/index.php/downloads-all>
> cd <extraction_directory>
> sudo ./install.sh

### Error may occur when install eProsima

- Asio libary
  > Download from https://sourceforge.net/projects/asio/ or get it in ./thirdparty/ folder.
  > sudo apt-get install autoconf
  > autoreconf -i
  > ./configure
  > sudo make
  > sudo make

- ‘gettid’ was not declared in this scope
  > open ./eProsima_Fast-DDS-v2xxx-Linux/src/fastrtps/
  > edit CMakeLists.txt with TextEditor
  > add -pthread to build options in 
  `else()
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -pthread -Wall -pedantic -Wextra -Wno-unknown-pragmas -Wno-error=deprecated-declarations")
  `
