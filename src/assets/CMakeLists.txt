add_library(assets_interface INTERFACE)
target_include_directories(assets_interface INTERFACE include)

add_library(assets
src/assets.hpp
src/assets.cpp
src/asset_loader.hpp
src/asset_loader.cpp
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
    PRIVATE
        sfml-graphics
        sfml-audio
)