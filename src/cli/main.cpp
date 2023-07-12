#include <iostream>
#include <CLI/CLI.hpp>

#include "sine.hpp"


int main(int argc, char** argv)
{
    CLI::App app { "Audio Pipeline CLI interface" };

    app.require_subcommand();

    // Sine App
    CLI::App *sineApp = app.add_subcommand("sine", "A Sine Wave Generator");
    float freq = 440.0;
    float amp = 3.0;
    sineApp->add_option("-f,--freq", freq, "Parameter");
    sineApp->add_option("-a,--amp", amp, "Parameter");
    sineApp->callback([=] {sine(freq, amp);});

    CLI11_PARSE(app, argc, argv);

}

