/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: chanjun1
TASK: Labyrinth
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_ROW = 2005;
const int MAX_COL = 2005;
const char obs = '*';

int n, m;
int r, c;
long long x, y;
string maze[MAX_ROW];
bool isVisited[MAX_ROW][MAX_COL];
long long cacheLeft[MAX_ROW][MAX_COL];
long long cacheRight[MAX_ROW][MAX_COL];
long long res = 0;

void walk(int posY, int posX) {
    int nextPosY;
    int nextPosX;
    bool hasLargerLeftOrRight = false;

    if (x > cacheLeft[posY][posX]) {
        hasLargerLeftOrRight = true;
        nextPosY = posY;
        nextPosX = posX - 1;
        cacheLeft[posY][posX] = x;
        if (maze[nextPosY][nextPosX] != obs && x > 0) {
            x--;
            walk(nextPosY, nextPosX);
            x++;
        }
    }

    if (y > cacheRight[posY][posX]) {
        hasLargerLeftOrRight = true;
        cacheRight[posY][posX] = y;
        nextPosY = posY;
        nextPosX = posX + 1;
        if (maze[nextPosY][nextPosX] != obs && y > 0) {
            y--;
            walk(nextPosY, nextPosX);
            y++;
        }
    }

    if (!hasLargerLeftOrRight && isVisited[posY][posX]) {
        return;
    }

    if (!isVisited[posY][posX]) {
        res++;
    }


    isVisited[posY][posX] = true;


    // cerr << posY << " " << posX << endl;

    nextPosY = posY + 1;
    nextPosX = posX;
    if (maze[nextPosY][nextPosX] != obs) {
        walk(nextPosY, nextPosX);
    }

    nextPosY = posY - 1;
    nextPosX = posX;
    if (maze[nextPosY][nextPosX] != obs) {
        walk(nextPosY, nextPosX);
    }
}

int main() {
    cin >> n >> m;
    cin >> r >> c;
    cin >> x >> y;

    string block = "";

    for (int i = 0; i <= m + 1; i++) {
        block += obs;
    }

    maze[0] = block;
    for (int i = 1; i <= n; i++) {
        string tempInput;
        cin >> tempInput;
        maze[i] = obs + tempInput + obs;
    }
    maze[n + 1] = block;

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            isVisited[i][j] = false;
            cacheLeft[i][j] = 0;
            cacheRight[i][j] = 0;
        }
    }

    walk(r, c);
    cout << res << endl;
}
