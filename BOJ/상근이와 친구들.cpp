#include <iostream>

// 5717번 상근이와 친구들 

using namespace std;

int n, m;

int main() {
  while(1) {
    cin >> n >> m;
    if(!n && !m) break;
    cout << n + m << endl;
  }

  return 0;
}