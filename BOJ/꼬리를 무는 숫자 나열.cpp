#include <cmath>
#include <iostream>

// 1598번 꼬리를 무는 숫자 나열

using namespace std;

int a, b, row, col;

int main() {
  cin >> a >> b;
  a--;
  b--;
  row = abs(a / 4 - b / 4);
  col = abs(a % 4 - b % 4);
  cout << row + col;

  return 0;
}