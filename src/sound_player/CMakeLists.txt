add_library(sound_player_interface INTERFACE)
target_include_directories(sound_player_interface INTERFACE include)
target_link_libraries(sound_player_interface
    INTERFACE
        types
)

add_library(sound_player
src/sound_id.cpp
src/sound_cache.hpp
src/sound_cache.cpp
src/sound_player.hpp
src/sound_player.cpp
)

target_include_directories(sound_player
	PUBLIC
		include
	PRIVATE
		src
)

target_link_libraries(sound_player
    PUBLIC
        sound_player_interface
        types
    PRIVATE
        assets
        sfml-audio
)