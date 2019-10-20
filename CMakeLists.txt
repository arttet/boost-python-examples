cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(boost-python-examples LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules ${CMAKE_MODULE_PATH} CACHE STRING "" FORCE)

if (WIN32)
  if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install CACHE STRING "" FORCE)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build CACHE STRING "" FORCE)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build CACHE STRING "" FORCE)
  endif()
endif()

find_package(Python REQUIRED COMPONENTS Interpreter Development)

set(Boost_USE_STATIC_RUNTIME OFF)
set(BOOST_COMPONENTS python${Python_VERSION_MAJOR}.${Python_VERSION_MINOR})

include(Functions)
include(Boost)

find_package(ClangDevTools)
find_package(Cppcheck)

enable_testing()

add_subdirectory(01-HelloWorld)
add_subdirectory(02-ExposingClasses)
add_subdirectory(03-Constructors)
add_subdirectory(04-ClassMembers)
add_subdirectory(05-Inheritance)
add_subdirectory(06-VirtualFunctionsInPython)
add_subdirectory(07-Operators)
add_subdirectory(08-CallPolicies)
add_subdirectory(09-Overloading)
add_subdirectory(10-Embedding)
add_subdirectory(11-Iterators)
add_subdirectory(12-Exceptions)
add_subdirectory(13-AutoInstantiation)
