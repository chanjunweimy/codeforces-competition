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
#include <list>

using namespace std;

const int MAX_ROW = 2005;
const int MAX_COL = 2005;
const char obs = '*';

struct Coor {
    int row;
    int col;
};

int n, m;
int r, c;
long long x, y;
string maze[MAX_ROW];
bool isVisited[MAX_ROW][MAX_COL];
long long cacheLeft[MAX_ROW][MAX_COL];
long long cacheRight[MAX_ROW][MAX_COL];
long long res = 0;
list<Coor> failedLeft;
list<Coor> failedRight;

void walk(int posY, int posX) {
    int nextPosY;
    int nextPosX;
    if (isVisited[posY][posX]) {
        if (x > cacheLeft[posY][posX]) {
            long long diffX = x - cacheLeft[posY][posX];
            for (list<Coor>::iterator it = failedLeft.begin(); it != failedLeft.end(); ++it) {
                Coor coor = *it;
                if (isVisited[coor.row][coor.col - 1]) {
                    continue;
                }
                long long tempX = x;
                cacheLeft[coor.row][coor.col] += diffX;
                x = cacheLeft[coor.row][coor.col];
                walk(coor.row, coor.col - 1);
                x = tempX;
            }
            cacheLeft[posY][posX] = x;
        }

        if (y > cacheRight[posY][posX]) {
            long long diffY = y - cacheRight[posY][posX];
            for (list<Coor>::iterator it = failedRight.begin(); it != failedRight.end(); ++it) {
                Coor coor = *it;
                if (isVisited[coor.row][coor.col + 1]) {
                    continue;
                }
                long long tempY = y;
                cacheRight[coor.row][coor.col] += diffY;
                y = cacheRight[coor.row][coor.col];
                walk(coor.row, coor.col + 1);
                y = tempY;
            }
            cacheRight[posY][posX] = y;
        }
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

    Coor coor;
    coor.row = posY;
    coor.col = posX;

    nextPosY = posY;
    nextPosX = posX - 1;
    if (maze[nextPosY][nextPosX] != obs) {
        if (x > 0) {
            x--;
            walk(nextPosY, nextPosX);
            x++;
        } else {
            failedLeft.push_front(coor);
        }
    }

    nextPosY = posY;
    nextPosX = posX + 1;
    if (maze[nextPosY][nextPosX] != obs) {
        if (y > 0) {
            y--;
            walk(nextPosY, nextPosX);
            y++;
        } else {
            failedRight.push_front(coor);
        }
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
