add_library(loguru
    include/loguru/loguru.hpp
    loguru.cpp
)

target_include_directories(loguru
PUBLIC
    include
)

target_compile_options(loguru
PRIVATE
    "-lstdc++ -lpthread -ldl"
)