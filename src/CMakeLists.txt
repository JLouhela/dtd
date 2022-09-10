add_executable(testlib 
    main.cpp
)


target_link_libraries(testlib
	PRIVATE
        sfml-window
        sfml-graphics)