#include <iostream>

// 4589번 Gnome Sequencing

using namespace std;

int n, a, b, c;

int main() {
  cin >> n;
  cout << "Gnomes:" << endl;
  for(int i = 1; i <= n; i++) {
    cin >> a >> b >> c;
    if(a < b && b < c || a > b && b > c) cout << "Ordered" << endl;
    else cout << "Unordered" << endl;
  }

  return 0;
}