cmake_minimum_required(VERSION 3.13)
project(Dragon)


find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

link_libraries(sfml-graphics)

add_executable(
    Dragon ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/graphics.h
        ${PROJECT_SOURCE_DIR}/src/graphics.cpp
        ${PROJECT_SOURCE_DIR}/src/bundle.h
        ${PROJECT_SOURCE_DIR}/src/bundle.cpp
        ${PROJECT_SOURCE_DIR}/src/fractal.h
        ${PROJECT_SOURCE_DIR}/src/fractal.cpp
        ${PROJECT_SOURCE_DIR}/src/version.h
        ${PROJECT_SOURCE_DIR}/src/config.h
    )
target_include_directories(Dragon PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_compile_features(Dragon PRIVATE cxx_std_17)

file(COPY ${PROJECT_SOURCE_DIR}/assets/DejaVuSans.ttf DESTINATION ${CMAKE_CURRENT_BINARY_DIR})