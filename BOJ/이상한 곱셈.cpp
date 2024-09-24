#include <iostream>

// 1225번 이상한 곱셈

using namespace std;

long long sum;
string a, b;

int main() {
  cin >> a >> b;
  for(char i: a) {
    for(char j: b) {
      sum += (long long)(i - '0') * (long long)(j - '0');
    }
  }
  cout << sum;

  return 0;
}