#include <iostream>

// 2530번 인공지능 시계

using namespace std;

int a, b, c, d;

int main() {
  cin >> a >> b >> c >> d;
  c += d % 60;
  d /= 60;
  if (c >= 60) {
    b++;
    c -= 60;
  }
  b += d % 60;
  d /= 60;
  if (b >= 60) {
    a++;
    b -= 60;
  }
  a += d;
  if (a >= 24)
    a %= 24;

  cout << a << " " << b << " " << c;

  return 0;
}