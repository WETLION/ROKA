#include <iostream>
#include <cmath>
#include <algorithm>

// 1925번 삼각형

using namespace std;

int x[3], y[3], l[3];

string angle(int a, int b, int c) {
  if(a + b == c) return "Jikkak";
  if(a + b > c) return "Yeahkak";
  return "Dunkak";
}

int main() {
  for(int i = 0; i < 3; i++) {
    cin >> x[i] >> y[i];
  }
  if((y[2] - y[1]) * (x[1] - x[0]) == (y[1] - y[0]) * (x[2] - x[1])) {
    cout << 'X';
    return 0;
  }
  for(int i = 0; i < 3; i++) {
    l[i] = pow(abs(x[i] - x[(i + 1) % 3]), 2) + pow(abs(y[i] - y[(i + 1) % 3]), 2);
  }
  sort(l, l + 3);
  if(l[0] == l[1] && l[1] == l[2]) cout << "Jung";
  else if(l[0] == l[1]) {
    cout << angle(l[0], l[1], l[2]) << "2";
  }
  else if(l[1] == l[2]) {
    cout << angle(l[1], l[2], l[0]) << "2";
  }
  else {
    cout << angle(l[0], l[1], l[2]);
  }

  cout << "Triangle";

  return 0;
}