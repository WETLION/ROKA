#include <iostream>
#include <algorithm>

// 2212번 센서

using namespace std;

int n, k, arr[10000], ans, len[10000];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n--);
    for(int i = 0; i < n; i++) len[i] = arr[i + 1] - arr[i];
    sort(len, len + n);
    for(int i = 0; i <= n - k; i++) ans += len[i];
    cout << ans;

    return 0;
} 