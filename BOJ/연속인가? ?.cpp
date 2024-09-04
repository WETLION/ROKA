#include <iostream>

// 26517번 연속인가? ?

using namespace std;

long long k, a, b, c, d;

int main() {
  cin >> k >> a >> b >> c >> d;
  if(a * k + b == c * k + d) cout << "Yes " << a * k + b;
  else cout << "No";

  return 0;
}