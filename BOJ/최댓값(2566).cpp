#include <iostream>

// 2566번 최댓값

using namespace std;

int input, MAX = -1, row, col;

int main() {
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            cin >> input;
            if(MAX < input) {
                MAX = input;
                row = i;
                col = j;
            }
        }
    }
    cout << MAX << endl << row << " " << col;

    return 0;
}
