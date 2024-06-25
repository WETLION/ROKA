#include <iostream>

// 1075번 나누기

using namespace std;

int n, f;

int main() {
  cin >> n >> f;
  n = n / 100 * 100;
  for(int i = 0; i <= 100; i++) {
    if((n + i) % f == 0) {
      if(i < 10) cout << "0";
      cout << i;
      break;
    }
  }

  return 0;
}