# CMakeLists files in this project can
# refer to the root source directory of the project as ${DTD_SOURCE_DIR} and
# to the root binary directory of the project as ${DTD_BINARY_DIR}.
cmake_minimum_required (VERSION 3.9.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project (Dtd VERSION 0.0.1 LANGUAGES CXX)

set(TMXLITE_STATIC_LIB TRUE)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
set(BUILD_SHARED_LIBS FALSE)

add_subdirectory(lib)
link_libraries(loguru)

if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

link_libraries(math)

add_subdirectory(bin)
add_subdirectory(src)
add_subdirectory(assets)

#enable_testing()
#add_subdirectory(test)