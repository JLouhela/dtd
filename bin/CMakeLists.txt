add_executable(dtd 
    main.cpp
)


target_link_libraries(dtd
	PRIVATE
        sfml-window
        sfml-graphics)