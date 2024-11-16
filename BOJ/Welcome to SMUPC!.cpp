#include <iostream>

// 29699번 Welcome to SMUPC!

using namespace std;

int n;
string str = "WelcomeToSMUPC";

int main() {
    cin >> n;
    cout << str[(n - 1) % 14];

    return 0;
}