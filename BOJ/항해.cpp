#include <iostream>

// 32200번 항해 

using namespace std;

int n, a, x, y, eat, waste, piece;

int main() {
  cin >> n >> x >> y;
  y -= x;
  while(n--) {
    cin >> a;
    eat += piece = a / x;
    a -= x * piece + piece * y;
    if(a > 0) waste += a; 
  }
  cout << eat << endl << waste;

  return 0;
}