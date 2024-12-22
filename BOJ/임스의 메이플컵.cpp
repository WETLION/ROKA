#include <iostream>

// 29790번 임스의 메이플컵 

using namespace std;

int n, u, l;

int main() {
  cin >> n >> u >> l;
  if(n >= 1000) {
    if(u >= 8000 || l >= 260) cout << "Very Good";
    else cout << "Good";
  }
  else cout << "Bad";

  return 0;
}