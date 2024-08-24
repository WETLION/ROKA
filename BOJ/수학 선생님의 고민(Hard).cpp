#include <iostream>
#include <cmath>
#include <algorithm>

// 28242번 수학 선생님의 고민(Hard)

using namespace std;

long long n, num_sqrt, route, a, b, c, d;

long long _gcd(long long a, long long b) {
  return a % b ? _gcd(b, a % b) : b;
}

int main() {
  cin >> n;
  route = 5 * n * n + 10 * n + 1;
  num_sqrt = sqrt(route);
  if(pow(num_sqrt, 2) == route) {
    int son_1 = - n - 1 + num_sqrt, son_2 = - n - 1 - num_sqrt, mom = 2 * n;
    int gcd_1 = _gcd(max(son_1, mom), min(son_1, mom)), gcd_2 = _gcd(max(son_2, mom), min(son_2, mom));
    pair<int, int> ap = {-(son_1) / gcd_1, mom / gcd_1}, bp = {-(son_2) / gcd_2, mom / gcd_2};
    if(ap.second * bp.second <= n && n % ap.second == 0 && n % bp.second == 0) {
      a = ap.second;
      b = ap.first;
      n /= ap.second;
      c = n;
      d = bp.first * n / bp.second;
      cout << a << " " << b << " " << c << " " << d;
    }
    else cout << -1;
  }
  else cout << -1;

  return 0;
}