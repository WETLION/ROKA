#include <iostream>

// 2501번 약수 구하기

using namespace std;

int n, k, cnt;

int main() {
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    if(n % i == 0) {
      cnt++;
      if(cnt == k) {
        cout << i;
        return 0;
      }
    }
  }
  cout << 0;

  return 0;
}