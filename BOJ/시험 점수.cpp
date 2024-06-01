#include <iostream>
#include <algorithm>

// 5596번 시험 점수

using namespace std;

int sum() {
  int input, n = 0;
  for(int i = 0; i < 4; i++) {
    cin >> input;
    n += input;
  }
  return n;
}

int main() {
  cout << max(sum(), sum());

  return 0;
}