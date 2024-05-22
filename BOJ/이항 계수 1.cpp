#include <iostream>

// 11050번 이항 계수 1

using namespace std;

int factorial(int n) { return n ? factorial(n - 1) * n : 1; }

int n, k;

int main() {
  cin >> n >> k;
  cout << factorial(n) / factorial(k) / factorial(n - k);
}