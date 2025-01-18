#include <iostream>

// 17204번 죽음의 게임 

using namespace std;

int n, k, arr[200], chk[200], now, cnt;

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  while(!chk[now]) {
    chk[now] = 1;
    if(now == k) {
      cout << cnt;
      return 0;
    }
    now = arr[now];
    cnt++;
  }
  cout << -1;

  return 0;
}