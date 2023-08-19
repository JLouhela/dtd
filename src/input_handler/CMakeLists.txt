add_library(input_handler_interface INTERFACE)
target_include_directories(input_handler_interface INTERFACE include)

add_library(input_handler
    src/input_handler.hpp
    src/input_handler.cpp
)

target_include_directories(input_handler
	PUBLIC
		include
	PRIVATE
		src
)

target_link_libraries(input_handler
    PUBLIC
        input_handler_interface
    PRIVATE
        sfml-window
        event_handler_interface
)