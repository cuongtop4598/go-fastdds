# Go-fastdds

Simple Golang connector for eProsima Fast DDS

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
  > open the file build error with IDE Editor
  > add following in header file
  `
  #include <sys/syscall.h>
  #define gettid() syscall(SYS_gettid)
  `

## Generate c++ sample
>
> fastddsgen -example CMake Shape.idl
