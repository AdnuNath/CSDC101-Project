#ifndef SOUND_H
#define SOUND_H

// ==============================
// SOUND MANAGER
// ==============================

#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class SoundManager
{
private:
    sf::Music bgm;

    sf::SoundBuffer bufPress;
    sf::SoundBuffer bufClick;
    sf::SoundBuffer bufDeath;
    sf::SoundBuffer bufDefeat;
    sf::SoundBuffer bufWin;

    unique_ptr<sf::Sound> sndPress;
    unique_ptr<sf::Sound> sndClick;
    unique_ptr<sf::Sound> sndDeath;
    unique_ptr<sf::Sound> sndDefeat;
    unique_ptr<sf::Sound> sndWin;

    SoundManager() {}
    SoundManager(const SoundManager &) = delete;
    SoundManager &operator=(const SoundManager &) = delete;

public:
    static SoundManager &getInstance()
    {
        static SoundManager instance;
        return instance;
    }

    void loadAll()
    {
        ofstream log("sound_log.txt");

        if (!bgm.openFromFile("music/bgm.mp3"))
        {
            log << "FAILED: music/bgm.mp3\n";
            cout << "[Sound] FAILED: music/bgm.mp3\n";
        }
        else
        {
            log << "OK: music/bgm.mp3\n";
            bgm.setLooping(true);
            bgm.setVolume(50.f);
        }

        auto loadBuf = [&](sf::SoundBuffer &buf,
                           unique_ptr<sf::Sound> &snd,
                           const string &path,
                           float vol)
        {
            if (!buf.loadFromFile(path))
            {
                log << "FAILED: " << path << "\n";
                cout << "[Sound] FAILED: " << path << "\n";
                snd = nullptr;
            }
            else
            {
                log << "OK: " << path << "\n";
                snd = make_unique<sf::Sound>(buf);
                snd->setVolume(vol);
            }
        };

        // --- diagnostic for MP3 loading issues ---
        {
            ifstream testOpen("music/press.mp3", ios::binary);
            if (!testOpen.is_open())
            {
                log << "DIAG press: ifstream CANNOT open music/press.mp3\n";
                log << "  -> file is missing OR exe is running from the wrong directory\n";
                cout << "[Sound] DIAG: music/press.mp3 not found (wrong cwd or missing file)\n";
            }
            else
            {
                testOpen.seekg(0, ios::end);
                long sz = (long)testOpen.tellg();
                log << "DIAG press: file opened OK, size=" << sz << " bytes\n";
                testOpen.close();

                sf::SoundBuffer tmpBuf;
                if (!tmpBuf.loadFromFile("music/press.mp3"))
                {
                    log << "DIAG press: sf::SoundBuffer::loadFromFile FAILED\n";
                    log << "  -> MP3 decode failed. Convert press.mp3 to press.wav or press.ogg\n";
                    log << "     and update the path below to match.\n";
                    cout << "[Sound] DIAG: SoundBuffer decode FAILED - convert to WAV/OGG\n";
                }
                else
                {
                    log << "DIAG press: SoundBuffer OK ("
                        << tmpBuf.getSampleCount() << " samples, "
                        << tmpBuf.getSampleRate() << " Hz, "
                        << tmpBuf.getChannelCount() << " ch)\n";
                    cout << "[Sound] DIAG: press.mp3 loaded fine in tmp test\n";
                }
            }
        }
        // --- end diagnostic ---

        loadBuf(bufPress, sndPress, "music/press.mp3", 100.f);
        loadBuf(bufClick, sndClick, "music/clickinteract.mp3", 80.f);
        loadBuf(bufDeath, sndDeath, "music/death.mp3", 90.f);
        loadBuf(bufDefeat, sndDefeat, "music/defeat.mp3", 90.f);
        loadBuf(bufWin, sndWin, "music/Wiin.mp3", 90.f);

        log.close();
    }

    void playBGM() { bgm.play(); }
    void stopBGM() { bgm.stop(); }
    void pauseBGM() { bgm.pause(); }

    // Movement key sound.

    void playPress()
    {
        if (!sndPress)
            return;
        sndPress->stop();
        sndPress->play();
    }

    void playClick()
    {
        if (!sndClick)
            return;
        sndClick->stop();
        sndClick->play();
    }

    void playDeath()
    {
        if (!sndDeath)
            return;
        sndDeath->stop();
        sndDeath->play();
    }

    void playDefeat()
    {
        stopBGM();
        if (!sndDefeat)
            return;
        sndDefeat->stop();
        sndDefeat->play();
    }

    void playWin()
    {
        if (!sndWin)
            return;
        sndWin->stop();
        sndWin->play();
    }

    void waitForDefeat()
    {
        if (!sndDefeat)
            return;
        while (sndDefeat->getStatus() == sf::SoundSource::Status::Playing)
            sf::sleep(sf::milliseconds(100));
    }
};

inline SoundManager &SFX()
{
    return SoundManager::getInstance();
}

#endif