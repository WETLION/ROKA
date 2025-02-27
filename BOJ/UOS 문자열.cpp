#include <iostream>

// 32929번 UOS 문자열

using namespace std;

int n;
string str = "UOS";

int main() {
    cin >> n;
    cout << str[--n % 3];

    return 0;
}