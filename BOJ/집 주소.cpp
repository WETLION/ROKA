#include <iostream>

// 1284번 집 주소

using namespace std;

int n;

int main() {
  while (1) {
    cin >> n;
    if (!n)
      break;
    int sum = 1;
    while (n > 0) {
      if (n % 10 == 0)
        sum += 5;
      else if (n % 10 == 1)
        sum += 3;
      else
        sum += 4;
      n /= 10;
    }
    cout << sum << endl;
  }

  return 0;
}