/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: chanjun1
TASK: Vova and Train
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    int t;
    long long L, v, l, r;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> L >> v >> l >> r;
        long long blocked = r / v - l / v;
        long long ans = L / v - blocked;
        if (l % v == 0) {
            ans--;
        }
        cout << ans << endl;
    }
    return 0;
}
