#include <cmath>
#include <iostream>

// 4696번 St. Ives

using namespace std;

int main() {
  double n;
  cout << fixed;
  cout.precision(2);
  while (1) {
    cin >> n;
    if (n == 0)
      break;
    double sum = 0;
    for (int i = 0; i <= 4; i++) {
      sum += pow(n, i);
    }
    cout << sum << endl;
  }

  return 0;
}