#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

// 1643번 쿠폰

using namespace std;

vector<int> v, vv;

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

__int128 gcd(__int128 a, __int128 b) { return a % b == 0 ? b : gcd(b, a % b); }

int main() {
  // ios::sync_with_stdio(0);
  // cout.tie(0);
  // cin.tie(0);
  int n;
  while (cin >> n)
    vv.push_back(n);
  while (!vv.empty()) {
    n = vv.front();
    vv.erase(vv.begin(), vv.begin() + 1);
    if (n == 1) {
      cout << 1 << '\n';
      continue;
    }
    __int128 cnt = 1, up = 0, down = 1, g_c_d;
    for (int i = 1; i < n; i++) {
      v.push_back(i);
      down *= i;
    }
    for (auto i : v) {
      up += n * down / i;
    }

    g_c_d = gcd(max(up, down), min(up, down));
    down /= g_c_d;
    up /= g_c_d;
    if (down == 1)
      cout << up + 1;
    else {
      cnt += up / down;
      up %= down;
      for (int i = 0; i <= (int)log10(cnt) + 1; i++)
        cout << " ";
      cout << up << '\n' << cnt << " ";
      for (int i = 0; i <= (int)log10(down); i++)
        cout << "-";
      cout << "\n";
      for (int i = 0; i <= (int)log10(cnt) + 1; i++)
        cout << " ";
      cout << down;
    }
    cout << '\n';
    v.clear();
  }

  return 0;
}