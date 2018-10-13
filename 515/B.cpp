/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: chanjun1
TASK: Heaters
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    const int MAX_R = 1005;
    int n ,r;
    int house[MAX_R];
    int warm[MAX_R];
    int highest = -1;
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> house[i];
        warm[i] = 0;
    }
    int minHeaters = 0;
    for (int i = 0; i < n; i++) {
        if (house[i] == 0) {
            continue;
        }
        minHeaters++;
        for (int j = max(0, i - r + 1); j <= min(n - 1, i + r - 1); j++) {
            // cerr << j << " ";
            warm[j]++;
        }
        // cerr << endl;
    }

    for (int i = 0; i < n; i++) {
        if (warm[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        cerr << warm[i] << " ";
    }
    cerr << endl;
    */

    for (int i = 0; i < n; i++) {
        if (house[i] == 0) {
            continue;
        }
        bool isRedundant = true;
        for (int j = max(0, i - r + 1); j <= min(n - 1, i + r - 1); j++) {
            if (warm[j] == 1) {
                isRedundant = false;
                break;
            }
        }
        if (!isRedundant) {
            continue;
        }
        minHeaters--;
        for (int j = max(0, i - r + 1); j <= min(n - 1, i + r - 1); j++) {
            warm[j]--;
        }

        /*
        for (int i = 0; i < n; i++) {
            cerr << warm[i] << " ";
        }
        cerr << endl;
        */
    }

    cout << minHeaters << endl;

    return 0;
}
