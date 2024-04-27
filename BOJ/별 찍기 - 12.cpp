#include <cmath>
#include <iostream>

// 2522번 별 찍기 - 12

using namespace std;

int n, num;

int main() {
  cin >> n;
  for (int i = 1; i < n * 2; i++) {
    for (int j = 0; j < abs(n - i); j++) {
      cout << ' ';
    }
    for (int j = 0; j < n - abs(n - i); j++) {
      cout << '*';
    }
    cout << endl;
  }

  return 0;
}