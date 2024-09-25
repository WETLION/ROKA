#include <iostream>
#include <cmath>

// 17829번 222-풀링

using namespace std;

int pulling(int before[1100][1100], int n){
  if(n == 1) return before[0][0];
  int after[1100][1100];
  n /= 2;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int MAX, MAX_2;
      MAX = MAX_2 = -100000;
      for(int k = i * 2; k <= i * 2 + 1; k++) {
        for(int l = j * 2; l <= j * 2 + 1; l++) {
          if(MAX < before[k][l]) {
            MAX_2 = MAX;
            MAX = before[k][l];
          }
          else if(MAX >= before[k][l] && MAX_2 < before[k][l]) MAX_2 = before[k][l];
          // cout << before[k][l] << " ";
        }
        // cout << endl;
      }
      after[i][j] = MAX_2;
      // cout << MAX_2 << " ";
    }
    // cout << endl;
  }
  return pulling(after, n);
}

int main() {
  int arr[1100][1100], n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  cout << pulling(arr, n);

  return 0;
}