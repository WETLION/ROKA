#include <iostream>

// 1371번 가장 많은 문자

using namespace std;

int arr[30], ans;
string str;

int main() {
    while(1) {
        cin >> str;
        if(cin.eof()) break;
        for(char i: str) {
            ans = max(ans, ++arr[i - 'a']);
        }
    }
    for(int i = 0; i < 26; i++) {
        if(ans == arr[i]) cout << char('a' + i);
    }

    return 0;
}