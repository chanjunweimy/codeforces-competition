/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: chanjun1
TASK: palindrome
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int ALPHA = 26;

int main() {
    int n;
    int alphaCount[ALPHA];
    string s;
    cin >> n >> s;

    for (int i = 0; i < ALPHA; i++) {
        alphaCount[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int index = s[i] - 'a';
        alphaCount[index]++;
    }

    string output = "";
    for (int i = 0; i < ALPHA; i++) {
        while (alphaCount[i] > 0) {
            alphaCount[i]--;
            n--;
            char outChar = 'a' + i;
            output = output + outChar;
        }
    }
    cout << output << endl;
}
