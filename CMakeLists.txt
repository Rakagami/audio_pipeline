cmake_minimum_required(VERSION 3.15)

if(NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

project(
    audio_pipeline
    VERSION 0.0.1
    DESCRIPTION "Audio Pipeline & DSP Playground"
    LANGUAGES CXX C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(Dependencies.cmake)
setup_dependencies()

add_subdirectory(src)

#add_library(project_options INTERFACE)
#target_compile_features(project_options INTERFACE cxx_std_17)
#
#add_library(project_warnings INTERFACE)
#
## standard compiler warnings
#include(cmake/CompilerWarnings.cmake)
#set_project_warnings(project_warnings)

# enable doxygen
# include(cmake/Doxygen.cmake)
# enable_doxygen()
