#include <iostream>

// 14222번 배열과 연산 

using namespace std;

int n, k, cnt[100], input;

int sort_chk() {
  if(cnt[n] > 1) return -1;
  int count = 0, chk = 0;
  for(int i = 1; i <= n; i++) {
    if(cnt[i] != 1) chk = 1;
    count += cnt[i];
  }
  if(count < n) chk = -1;
  return chk;
}

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> input;
    cnt[input]++;
  }
  while(1) {
    for(int i = 1; i <= n; i++) {
      if(cnt[i] > 1) {
        cnt[i]--;
        cnt[i + k]++;
        break;
      }
    }
    int chk = sort_chk();
    if(chk < 0) {
      cout << 0;
//			cin >> n;
      return 0;
    }
    else if(!chk) break;
  }
  cout << 1;
//	cin >> n;

  return 0;
}