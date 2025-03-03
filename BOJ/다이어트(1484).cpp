#include <iostream>
#include <vector> 

// 1484번 다이어트

using namespace std;

int n, f = 0, b = 2, ff, bb;
vector<int> v;

int main() {
  cin >> n;
  while(f < b - 1) {
    ff = ++f * f;
    bb = b * b;
    while(bb - ff < n) bb = ++b * b;
    if(bb - ff == n) v.push_back(b);
  }
  for(int i: v) cout << i << endl;
  if(v.empty()) cout << -1;
  cin >> n;

  return 0;
} 