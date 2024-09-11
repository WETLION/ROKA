#include <iostream>

// 4880번 다음수

using namespace std;

int a, b, c;

int main() {
  while(1) {
    cin >> a >> b >> c;
    if(!a && !b && !c) break;
    if(b - a == c - b) cout << "AP " << c + b - a << endl;
    else cout << "GP " << c * b / a << endl;
  }

  return 0;
}