#include <iostream>

// 27959번 초코바

using namespace std;

int n, m;

int main() {
  cin >> n >> m;
  if(n * 100 >= m) cout << "Yes";
  else cout << "No";

  return 0;
}