#include <iostream>
#include <vector>
#include <algorithm>

// 9070번 장보기

using namespace std;

int t, n, w, c;

struct node {
  int weight, cash, origin;
};

bool cmp(node a, node b) {
  return a.weight == b.weight && a.cash == b.cash ? a.origin < b.origin : (double)a.cash / a.weight < (double)b.cash / b.weight;
}

int gcd(int a, int b) {
  return a % b ? gcd(b, a % b) : b;
}

int main() {
  cin >> t;
  while(t--) {
    cin >> n;
    vector<node> v;
    for(int i = 0; i < n; i++) {
      cin >> w >> c;
      int _gcd = gcd(max(w, c), min(w, c));
      v.push_back({w / _gcd, c / _gcd, c});
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0].origin << endl;
  }

  return 0;
}