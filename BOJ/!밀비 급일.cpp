#include <iostream>
#include <algorithm>
#include <string>

// 11365번 !밀비 급일

using namespace std;

int main() {
    string input;
    while(1) {
        getline(cin, input);
        if(input == "END") break;
        reverse(input.begin(), input.end());
        cout << input << endl;
    }

    return 0;
}