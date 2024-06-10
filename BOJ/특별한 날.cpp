#include <iostream>

// 10768번 특별한 날

using namespace std;

int m, d;

int main() {
    cin >> m >> d;
    if(m == 2 && d == 18) cout << "Special";
    else if(m < 2 || m == 2 && d < 18) cout << "Before";
    else cout << "After";

    return 0;
}