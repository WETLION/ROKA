#include <iostream>

// 1267번 휴대폰 요금

using namespace std;

int n, input, sum_a, sum_b;

int main() {
  cin >> n;
  while (n--) {
    cin >> input;
    sum_a += input / 30 + 1;
    sum_b += input / 60 + 1;
  }
  sum_a *= 10;
  sum_b *= 15;
  if (sum_a < sum_b)
    cout << "Y " << sum_a;
  else if (sum_a > sum_b)
    cout << "M " << sum_b;
  else
    cout << "Y M " << sum_a;
  return 0;
}