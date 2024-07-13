#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

// 1524번 세준세비

using namespace std;

int t, n, m, input;
vector<int> s, b;

int main() {
  cin >> t;
  while(t--) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
      scanf("%d", &input);
      s.push_back(input);
    }
    for(int i = 0; i < m; i++) {
      scanf("%d", &input);
      b.push_back(input);
    }
    sort(s.begin(), s.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    while(1) {
      if(s.empty()) {
        b.clear();
        cout << "B" << endl;
        break;
      }
      if(b.empty()) {
        s.clear();
        cout << "S" << endl;
        break;
      }
      if(s.back() < b.back()) s.pop_back();
      else b.pop_back();
    }
  }

  return 0;
}