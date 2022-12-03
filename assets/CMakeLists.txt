configure_file(asset_path.hpp.in asset_path.hpp)
target_include_directories(assets PRIVATE ${CMAKE_CURRENT_BINARY_DIR})