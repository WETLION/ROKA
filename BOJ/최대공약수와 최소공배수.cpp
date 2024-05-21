#include <iostream>

// 2609번 최대공약수와 최소공배수

using namespace std;

int a, b;

int gcd(int a, int b) {
  return a % b ? gcd(b, a % b) : b;
}

int main() {
  cin >> a >> b;
  int _gcd = gcd(a, b);
  cout << _gcd << endl << a * b / _gcd;

  return 0;
}