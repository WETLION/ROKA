#include <iostream>

// 1074번 Z

using namespace std;

int n, r, c;

int pow(int a, int b) {
  int sum = 1;
  while(b--) sum *= a;
  return sum;
}

int find(int num, int start, int end, int x_s, int y_s) {
  if(!num) return start;
  int now = pow(2, --num);
  if(x_s + now > r) {
    if(y_s + now > c) {
      return find(num, start, end - 3 * pow(4, num), x_s, y_s);
    }
    else {
      return find(num, start + pow(4, num), end - 2 * pow(4, num), x_s, y_s + now);
    }
  }
  else {
    if(y_s + now > c) {
      return find(num, start + 2 * pow(4, num), end - pow(4, num), x_s + now, y_s);
    }
    else {
      return find(num, start + 3 * pow(4, num), end, x_s + now, y_s + now);
    }
  }
}

int main() {
  cin >> n >> r >> c;
  cout << find(n, 0, pow(2, n) - 1, 0, 0);

  return 0;
}