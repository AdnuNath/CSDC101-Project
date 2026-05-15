#ifndef PLAYER_H
#define PLAYER_H

#include <windows.h>
#include <conio.h>
#include <string>
#include "sound.h" // <-- for SFX

using namespace std;

// ==============================
// PLAYER CLASS
// ==============================
class Player
{

private:
    int x;
    int y;
    string name;

    int totalMoves;
    int crossingMoves;

public:
    // ==========================
    // CONSTRUCTOR
    // ==========================
    Player(int startX, int startY, string playerName = "Player")
    {
        x = startX;
        y = startY;
        name = playerName;
        totalMoves = 0;
        crossingMoves = 0;
    }

    // ==========================
    // GETTERS
    // ==========================
    int getX() { return x; }
    int getY() { return y; }

    string getName() { return name; }

    int getTotalMoves() { return totalMoves; }
    int getCrossingMoves() { return crossingMoves; }

    // ==========================
    // RESET POSITION
    // ==========================
    void resetPosition(int startX, int startY)
    {
        x = startX;
        y = startY;
        crossingMoves = 0; // Recount
    }

    // ==========================
    // RESET CROSSING MOVES ONLY
    // ==========================

    void resetCrossingMoves()
    {
        crossingMoves = 0;
    }

    // ==========================
    // CARRY PLAYER (LOG RIDING)
    // ==========================

    bool carryX(int dir, int playableWidth)
    {
        x += dir;

        if (x < 1 || x > playableWidth)
        {
            return false;
        }

        return true;
    }

    // ==========================
    // HANDLE INPUT - REAL TIME
    // ==========================

    void handleInput(int totalRows, int playableWidth)
    {
        if (_kbhit())
        {
            int key = _getch();

            while (_kbhit())
            {
                key = _getch();
            }

            if (key == 224)
            {
                key = _getch();
            }

            bool moved = false;

            switch (key)
            {
            case 72:
            case 'w':
            case 'W':
                if (y > 0)
                {
                    y--;
                    moved = true;
                }
                break;

            case 80:
            case 's':
            case 'S':
                if (y < totalRows - 1)
                {
                    y++;
                    moved = true;
                }
                break;

            case 75:
            case 'a':
            case 'A':
                if (x > 1)
                {
                    x--;
                    moved = true;
                }
                break;

            case 77:
            case 'd':
            case 'D':
                if (x < playableWidth)
                {
                    x++;
                    moved = true;
                }
                break;
            }

            if (moved)
            {
                totalMoves++;
                crossingMoves++;

                SFX().playPress();
            }
        }
    }
};

#endif