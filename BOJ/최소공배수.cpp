#include <algorithm>
#include <iostream>

//1934번 최소공배수

using namespace std;

long long int euclid(long long int a, long long int b) {
  if (a % b == 0)
    return b;
  return euclid(b, a % b);
}

int main() {
  long long int a, b;
  cin >> a >> b;
  long long int gcd = euclid(max(a, b), min(a, b));
  for (int i = 0; i < gcd; i++) {
    cout << 1;
  }

  return 0;
}