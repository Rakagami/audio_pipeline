add_library(dsp_library dsp_library.cpp)

target_include_directories(dsp_library ${WARNING_GUARD} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                                                  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)

target_compile_features(dsp_library PUBLIC cxx_std_20)
