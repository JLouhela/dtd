add_executable(dtd 
    main.cpp
)


target_link_libraries(dtd
	PRIVATE
        loguru
        renderer
        game
        game_loop
        event_handler
)