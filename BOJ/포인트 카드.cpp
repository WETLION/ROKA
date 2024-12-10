#include <iostream>

// 14471번 포인트 카드

using namespace std;

int n, m, ans, a, b, MIN, chk;

int main() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    if(a >= b) continue;
    if(chk && MIN <= a) ans += n - a; // MIN이 0인 경우 파악 못함 
    else {
      if(chk) ans += n - MIN;
      MIN = a;
    }
    chk = 1;
  }
  cout << ans;

  return 0;
}