#include <audio_pipeline/dsp_library.hpp>

int factorial(int input)
{
    int result = 1;

    while (input > 0) {
        result *= input;
        --input;
    }

    return result;
}
