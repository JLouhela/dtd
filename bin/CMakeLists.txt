add_executable(dtd 
    main.cpp
)


target_link_libraries(dtd
	PRIVATE
        game
        game_loop
        renderer
)