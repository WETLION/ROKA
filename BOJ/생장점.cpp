#include <iostream>

// 1703번 생장점

using namespace std;

int a;

int main() {
  while(1) {
    cin >> a;
    if(!a) break;
    int sum = 1, s, d;
    while(a--) {
      cin >> s >> d;
      sum = sum * s - d;
    }
    cout << sum << endl;
  }

  return 0;
}