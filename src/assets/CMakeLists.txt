add_library(assets_interface INTERFACE)
target_include_directories(assets_interface INTERFACE include)

add_library(assets
src/assets.hpp
src/assets.cpp
src/asset_loader.hpp
src/asset_loader.cpp
src/level.hpp
src/level.cpp
src/level_parser.hpp
src/level_parser.cpp
)

target_include_directories(assets
	PUBLIC
		include
	PRIVATE
		src
)

target_link_libraries(assets
    PUBLIC
        assets_interface
        tmxlite
    PRIVATE
        sfml-audio
        sfml-graphics
)