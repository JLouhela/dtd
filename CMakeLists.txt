# CMakeLists files in this project can
# refer to the root source directory of the project as ${DTD_SOURCE_DIR} and
# to the root binary directory of the project as ${DTD_BINARY_DIR}.
cmake_minimum_required (VERSION 3.9.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project (Dtd VERSION 0.0.1 LANGUAGES CXX)

set(BUILD_SHARED_LIBS FALSE)
add_subdirectory(bin)
add_subdirectory(lib/SFML)
add_subdirectory(src)
#add_subdirectory(res)

#enable_testing()
#add_subdirectory(test)