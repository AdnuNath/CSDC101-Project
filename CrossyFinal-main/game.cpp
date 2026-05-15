#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <SFML/Audio.hpp>

#include "sound.h"
#include "player.h"
#include "map.h"
#include "leaderboard.h"
#include "ui.h"

using namespace std;

// ==============================
// TIMER — QueryPerformanceCounter
// ==============================
static LARGE_INTEGER gFreq;
static LARGE_INTEGER gStart;
static bool gStarted = false;

void timerReset()
{
    QueryPerformanceFrequency(&gFreq);
    gStarted = false;
}

void timerMarkStart()
{
    if (!gStarted)
    {
        QueryPerformanceCounter(&gStart);
        gStarted = true;
    }
}

long long timerMs()
{
    if (!gStarted)
        return 0;
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    return ((now.QuadPart - gStart.QuadPart) * 1000LL) / gFreq.QuadPart;
}

string timerStr()
{
    long long ms = timerMs();
    long long sec = ms / 1000;
    long long min = sec / 60;
    sec %= 60;
    ms %= 1000;
    char buf[32];
    sprintf(buf, "%02lld:%02lld.%03lld", min, sec, ms);
    return string(buf);
}

// ==============================
// START GAME
// ==============================
void startGame(string playerName, int difficulty)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD mode = 0;
    GetConsoleMode(hOut, &mode);

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, mode);
    SetConsoleOutputCP(CP_UTF8);

    int sleepDelay;
    if (difficulty == 0)
        sleepDelay = 180;
    else if (difficulty == 1)
        sleepDelay = 120;
    else
        sleepDelay = 80;

    int playableWidth = 40;
    int totalRows = 20;

    int zoneMap[20];
    vector<Obstacle> roadObstacles[20];
    vector<Obstacle> riverObstacles[20];

    Player player(21, 19, playerName);

    int lives = 3;
    int crossings = 0;

    srand(time(0));
    timerReset(); // fresh timer for this session

    SFX().playBGM();

    initializeZoneMap(zoneMap);
    initializeObstacles(zoneMap, roadObstacles, riverObstacles, totalRows);

    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    while (lives > 0)
    {
        Node *head = NULL;
        buildRoad(head, zoneMap, roadObstacles, riverObstacles, totalRows, playableWidth);

        int livesBefore = lives;
        carryPlayerOnLog(zoneMap, riverObstacles, player, lives, totalRows, playableWidth);

        if (lives < livesBefore)
        {
            if (lives == 0)
                SFX().playDefeat();
            else
                SFX().playDeath();
        }

        if (lives > 0)
        {
            int livesBefore2 = lives;
            int crossingsBefore = crossings;

            checkCollision(zoneMap, head, lives, player, crossings);

            if (crossings > crossingsBefore)
                SFX().playWin();

            if (lives < livesBefore2)
            {
                if (lives == 0)
                    SFX().playDefeat();
                else
                    SFX().playDeath();
            }
        }

        placePlayer(head, player, playableWidth);
        displayRoad(head, lives, crossings, player.getName());
        freeList(head);

        int movesBefore = player.getTotalMoves();
        player.handleInput(totalRows, playableWidth);

        if (!gStarted && player.getTotalMoves() > movesBefore)
            timerMarkStart();

        moveObstacles(zoneMap, roadObstacles, riverObstacles, totalRows, playableWidth);
        Sleep(sleepDelay);
    }

    long long finalMs = timerMs();
    string finalStr = timerStr();

    CONSOLE_CURSOR_INFO cursorInfo2;
    cursorInfo2.dwSize = 1;
    cursorInfo2.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo2);

    SFX().waitForDefeat();

    resetColor();
    savePlayer(playerName, crossings, finalStr, finalMs);
    gameOverScreen(playerName, crossings, finalStr);
}

int main()
{
    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

    DWORD prev_mode;
    GetConsoleMode(hIn, &prev_mode);

    SetConsoleMode(
        hIn,
        prev_mode & ~ENABLE_QUICK_EDIT_MODE);

    CONSOLE_CURSOR_INFO ci;
    ci.dwSize = 1;
    ci.bVisible = FALSE;

    SetConsoleCursorInfo(
        GetStdHandle(STD_OUTPUT_HANDLE),
        &ci);

    SFX().loadAll();
    runUI();

    return 0;
}