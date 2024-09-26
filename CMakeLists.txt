cmake_minimum_required(VERSION 3.5.0)

set(ZLIB_USE_STATIC_LIBS "ON")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

project(DesignPatterns VERSION 0.1.0 LANGUAGES CXX )

add_executable(AbstractFactoryPattern src/AbstractFactory/main.cpp)
add_executable(BuilderPattern src/Builder/main.cpp)
add_executable(Factory src/Factory/main.cpp)
add_executable(Prototype src/Prototype/main.cpp)
add_executable(Singleton src/Singleton/main.cpp)
add_executable(Adapter src/Adapter/main.cpp)
add_executable(Composite src/Composite/main.cpp)
add_executable(Decorator src/Decorator/main.cpp)