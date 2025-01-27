#include <iostream>
#include <algorithm>

// 16466번 콘서트

using namespace std;

int arr[1000001], n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) {
        if(arr[i] != i + 1) {
            cout << i + 1;
            return 0;
        }
    }
    cout << n + 1;

    return 0;
}