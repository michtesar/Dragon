cmake_minimum_required(VERSION 3.13)
project(Dragon)


find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

link_libraries(sfml-graphics)

add_executable(
    Dragon ${PROJECT_SOURCE_DIR}/src/main.cpp
    )
target_include_directories(Dragon PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_compile_features(Dragon PRIVATE cxx_std_17)