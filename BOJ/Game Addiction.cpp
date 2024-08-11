#include <iostream>
#include <cmath>
#include <algorithm>

// 20152번 Game Addiction

using namespace std;

ostream &operator<<(ostream &dest, __int128_t value) {
  ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(ios_base::badbit);
    }
  }
  return dest;
}

__int128_t ans = 1;
int h, n, diff;

int main() {
  cin >> h >> n;
  diff = abs(h - n);
  for(int i = diff + 1; i <= 2 * diff; i++) {
    if(i % 2 == 0) ans *= 2;
    else ans *= i;
    // cout << ans << endl;
  }
  for(int i = 2; i <= diff / 2; i++) {
    ans /= i;
  }
  cout << ans / (diff + 1);

  return 0;
}