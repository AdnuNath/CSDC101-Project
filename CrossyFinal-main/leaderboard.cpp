#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include "leaderboard.h"

using namespace std;

void savePlayer(string playerName, int score, string timeStr, long long timeMs)
{
    ofstream file("leaderboard.txt", ios::app);
    if (!file.is_open())
        return;

    file << playerName << "|"
         << score << "|"
         << timeStr << "|"
         << timeMs << "\n";

    file.close();
}

vector<playerLeaderboard> loadLeaderboard()
{
    ifstream file("leaderboard.txt");
    vector<playerLeaderboard> players;
    if (!file.is_open())
        return players;

    string line;
    while (getline(file, line))
    {
        if (line.empty())
            continue;

        playerLeaderboard p;

        if (line.find('|') == string::npos)
        {
            p.playerName = line;
            p.timeStr = "--:--.---";
            p.timeMs = 999999999LL;
            string scoreLine;
            if (getline(file, scoreLine))
                p.score = atoi(scoreLine.c_str());
            else
                p.score = 0;
        }
        else
        {
            stringstream ss(line);
            string token;
            getline(ss, token, '|');
            p.playerName = token;
            getline(ss, token, '|');
            p.score = atoi(token.c_str());
            getline(ss, token, '|');
            p.timeStr = token;
            getline(ss, token, '|');
            p.timeMs = (long long)atoll(token.c_str());
        }

        players.push_back(p);
    }

    file.close();

    sort(players.begin(), players.end(),
         [](const playerLeaderboard &a, const playerLeaderboard &b)
         {
             if (a.score != b.score)
                 return a.score > b.score;
             return a.timeMs < b.timeMs;
         });

    return players;
}