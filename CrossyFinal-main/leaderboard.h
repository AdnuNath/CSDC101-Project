#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>
#include <string>

using namespace std;

struct playerLeaderboard
{
    string playerName;
    int score;
    string timeStr;
    long long timeMs;
};

void savePlayer(string playerName, int score, string timeStr, long long timeMs);
vector<playerLeaderboard> loadLeaderboard();

#endif