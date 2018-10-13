/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: chanjun1
TASK: Books
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;


int main() {
    long long q;
    char command;
    int index;
    list<int> indexList;
    int pos[200005];
    bool isUpdated = false;
    int left = 0;
    int right = 0;

    cin >> q;
    for (long long i = 0; i < q; i++) {
        cin >> command >> index;
        if (command == 'L') {
            pos[index] = left;
            if (left == right) {
                right++;
            }
            left--;
            indexList.push_front(index);
        } else if (command == 'R') {
            pos[index] = right;
            if (right == left) {
                left--;
            }
            right++;
            indexList.push_back(index);
        } else if (command == '?') {
            int leftPop = pos[index] - left - 1;
            int rightPop = right - pos[index] - 1;
            cout << min(leftPop, rightPop) << endl;
        }
    }

    return 0;
}
