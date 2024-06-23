#include <iostream>

// 17296번 But can you do it in 0.5x A presses?

using namespace std;

int n, press, cnt;
double arr[1001];

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for(int i = 0; i < n; i++) {
    if(arr[i] > 0 && !press) {
      // cnt++;
      cnt += (int)arr[i];
      if(arr[i] - (int)arr[i] > 0) cnt++;
      press = 1;
    }
    else if(arr[i] >= 1) {
      cnt += (int)arr[i];
    }
  }
  cout << cnt;

  return 0;
}