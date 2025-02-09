#include <iostream>

// 23969번 알고리즘 수업 - 버블 정렬 2

using namespace std;

int n, k, arr[10001];

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for(int i = n - 1; i > 0; i--) {
    for(int j = 0; j < i; j++) {
      if(arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        if(!--k) {
          for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
          }
          cin >> n;

          return 0;
        }
      }
    }
  }
  cout << -1;
  cin >> n;

  return 0;
} 