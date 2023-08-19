add_executable(dtd 
    main.cpp
)


target_link_libraries(dtd
	PRIVATE
        assets
        loguru
        renderer
        game
        game_loop
        event_handler
        sound_player
        input_handler
)