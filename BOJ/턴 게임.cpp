#include <iostream>
#include <cmath>

// 12934번 턴 게임

using namespace std;

long long x, y, sq, cnt;

int main() {
  cin >> x >> y;
  sq = sqrt((x + y) * 2);
  if(sq * (sq + 1) == (x + y) * 2) {
    while(x) {
      if(sq > x) x = 0;
      else x -= sq--;
      cnt++;
    }
    cout << cnt;
  }
  else cout << -1;

  return 0;
}