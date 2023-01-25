#include "Level.h"

LevelSound::LevelSound()
{
}

LevelSound::~LevelSound()
{
}

void LevelSound::Initialize()
{
    sound.setLoop(false);
}

void LevelSound::PlayEndLevelSound()
{
    sound.stop();
    if (!buffer.loadFromFile("C:\\Labs\\ProjectWorks\\Game\\Game\\Resources\\smb_stage_clear.wav"))
        return;
    sound.setBuffer(buffer);
    sound.play();
}

void LevelSound::PlayDieSound()
{
    sound.stop();
    if (!buffer.loadFromFile("C:\\Labs\\ProjectWorks\\Game\\Game\\Resources\\smb_mariodie.wav"))
        return;
    sound.setBuffer(buffer);
    sound.play();
}
