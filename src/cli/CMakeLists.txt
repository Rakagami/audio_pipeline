add_executable(audio_pipeline_cli main.cpp sine.cpp)

target_link_libraries(
    audio_pipeline_cli
    PRIVATE
        CLI11::CLI11
        pulse-simple
    )
