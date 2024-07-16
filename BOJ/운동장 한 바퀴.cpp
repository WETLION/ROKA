#include <iostream>

// 16486번 운동장 한 바퀴

using namespace std;

int d1, d2;

int main() {
  cout << fixed;
  cout.precision(6);
  cin >> d1 >> d2;
  cout << d1 * 2 + 2 * d2 * 3.141592;

  return 0;
}