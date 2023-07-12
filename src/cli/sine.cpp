#include <cmath>
#include <cstdio>
#include <pulse/simple.h>

#define PI 3.14159265
#define SAMPLE_RATE 44100
#define DURATION 5

int sine(float frequency, float amplitude)
{
    pa_simple* s = nullptr;
    pa_sample_spec ss;

    ss.format = PA_SAMPLE_S16LE;
    ss.channels = 1;
    ss.rate = SAMPLE_RATE;

    int error = 0;
    if (!(s = pa_simple_new(
              nullptr, "Sine Wave", PA_STREAM_PLAYBACK, nullptr, "playback", &ss, nullptr, nullptr, &error))) {
        printf("pa_simple_new() failed\n");
        return -1;
    }

    float buffer[SAMPLE_RATE * DURATION];

    for (int i = 0; i < SAMPLE_RATE * DURATION; i++) {
        // NOLINTNEXTLINE
        buffer[i] = amplitude * sin(2 * PI * frequency * i / SAMPLE_RATE);
    }

    if (pa_simple_write(s, buffer, sizeof(buffer), &error) < 0) {
        printf("pa_simple_write() failed\n");
        return -1;
    }

    if (pa_simple_drain(s, &error) < 0) {
        printf("pa_simple_drain() failed\n");
        return -1;
    }

    pa_simple_free(s);

    return 0;
}
