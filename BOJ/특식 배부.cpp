#include <iostream>

// 27110번 특식 배부

using namespace std;

int n, a, b, c;

int main() {
    cin >> n >> a >> b >> c;
    cout << (n - a <= 0 ? n : a) + (n - b <= 0 ? n : b) + (n - c <= 0 ? n : c);

    return 0;
}