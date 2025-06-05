#include <iostream>

// 32775번 가희와 4시간의 벽 1

using namespace std;

int s, f;

int main() {
    cin >> s >> f;
    cout << (s > f ? "flight" : "high speed rail");
    
    return 0;
}