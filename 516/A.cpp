/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: chanjun1
TASK: triangle
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int TRI = 3;

int diffSide(int s1, int s2, int s3) {
    return s3 - (s1 + s2);
}


int main() {
    int tri[TRI];
    cin >> tri[0] >> tri[1] >> tri[2];

    // cerr << tri[0] << tri[1] << tri[2];

    int diff;
    int minutes = 0;
    while (true) {
        sort(tri, tri + TRI);
        // cerr << tri[0] << tri[1] << tri[2] << endl;
        diff = diffSide(tri[0], tri[1], tri[2]);
        if (diff < 0) {
            break;
        }
        tri[0] += diff + 1;
        minutes += diff + 1;
    }
    cout << minutes << endl;
    return 0;
}
