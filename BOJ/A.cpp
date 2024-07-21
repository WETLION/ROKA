#include <iostream>
#include <vector>
#include <algorithm>

// 13171번 A

using namespace std;

struct node {
  unsigned long long num, mod;
};

struct compare{
  bool operator() (const node &a, const unsigned long long &b) {
    return a.num < b;
  }
}; // num을 기준으로 찾기

unsigned long long a, x, ans;
vector<node> v, vv;

int main() {
  cin >> a >> x;
  a %= 1000000007;
  v.push_back({1, a});
  while(v.back().num * 2 <= x) {
    v.push_back({v.back().num * 2, (v.back().mod * v.back().mod) % 1000000007});
  }
  ans = v.back().mod;
  x -= v.back().num;
  while(x) {
    int location = lower_bound(v.begin(), v.end(), x, compare()) - v.begin();
    if(v[location].num > x) location--;
    // cout << v[location].num << endl;
    x -= v[location].num;
    ans *= v[location].mod;
    // cout << ans << endl;
    ans %= 1000000007;
  }
  cout << ans;

  return 0;
}