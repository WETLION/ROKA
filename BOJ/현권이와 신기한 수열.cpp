#include <iostream>
#include <unordered_set>

// 32172번 현권이와 신기한 수열

using namespace std;

unordered_set<int> s;
int n, arr[100001];

int main() {
    cin >> n;
    s.insert(0);
    for(int i = 1; i <= n; i++) {
        if(arr[i - 1] - i < 0 || s.find(arr[i - 1] - i) != s.end()) s.insert(arr[i] = arr[i - 1] + i);
        else s.insert(arr[i] = arr[i - 1] - i);
        //cout << arr[i] << endl;
    }
    cout << arr[n];

    return 0;
} 