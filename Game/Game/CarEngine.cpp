#include "CarEngine.h"

CarEngineSound::CarEngineSound()
{
}

CarEngineSound::~CarEngineSound()
{
}

void CarEngineSound::Initialize()
{
    sound.setLoop(true);
    for (int i = 0; i < NSAMPLES; i++)
    {
        samples[i] = (10000 * sin(130 * (2.0f * 3.1415f) * i / 44100));
    }
    buffer.loadFromSamples(samples, NSAMPLES, 1, 44100);
    sound.setBuffer(buffer);
}

void CarEngineSound::Update(float speed)
{
    sound.setPitch(1 + (speed / 2000));
}

void CarEngineSound::StopPlay()
{
    sound.stop();
}

void CarEngineSound::StartPlay()
{
    //sound.setLoop(true);
    sound.play();
}
