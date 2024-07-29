#include <iostream>

// 9295번 주사위

using namespace std;

int t, a, b;

int main() {
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cin >> a >> b;
    cout << "Case " << i << ": " << a + b << endl;
  }

  return 0;
}