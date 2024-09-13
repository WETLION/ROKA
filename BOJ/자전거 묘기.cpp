#include <iostream>

// 25706번 자전거 묘기

using namespace std;

int n, arr[200001], road[200001], END;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> road[i];
  }
  arr[--n] = 1;
  // arr[END = --n] = 1;
  END = n;
  // while(--n + 1)
  while(--n >= 0) {
    if(n + road[n] > END) {
      arr[n] = 1;
    }
    else if(!road[n]) {
      arr[n] = arr[n + 1] + 1;
    }
    else {
      arr[n] = arr[n + road[n] + 1] + 1;
    }
  }
  for(int i = 0; i <= END; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}