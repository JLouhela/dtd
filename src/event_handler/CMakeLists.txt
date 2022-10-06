add_library(event_handler_interface INTERFACE)
target_include_directories(event_handler_interface INTERFACE include)

add_library(event_handler
    src/event_handler.hpp
    src/event_handler.cpp
)

target_include_directories(event_handler
	PUBLIC
		include
	PRIVATE
		src
)

target_link_libraries(event_handler
    PUBLIC
        event_handler_interface
        sfml-window
)