#include <iostream>

// 4562번 No Brainer

using namespace std;

int n, a, b;

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a >> b;
    if(a < b) cout << "NO BRAINS" << endl;
    else cout << "MMM BRAINS" << endl;
  }

  return 0;
}