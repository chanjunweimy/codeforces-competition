/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: chanjun1
TASK: XOR
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

long long calRes(long long a) {
    long long res = 0;
    long long numOfOnes = 0;
    while (a > 0) {
        int lastDigit = a & 1;
        if (lastDigit == 1) {
            numOfOnes++;
        }
        a >>= 1;
    }

    long long powOfTwo = 1;
    for (long long i = 0; i < numOfOnes; i++) {
        powOfTwo *= 2;
    }
    return res + powOfTwo;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long a;
        cin >> a;
        cout << calRes(a) << endl;
    }
    return 0;
}
