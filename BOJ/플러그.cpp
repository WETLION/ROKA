#include <iostream>

// 2010번 플러그

using namespace std;

int main() {
  int n, sum = 1, input;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input;
    sum += input;
  }
  sum -= n;
  cout << sum;

  return 0;
}