#include <iostream>
#include <vector>
#include <algorithm> 

// 12099번 점심메뉴 

using namespace std;

struct node {
  int spicy, sweet;
};

int n, q, a, b, x, y;
vector<node> v;

bool cmp(node a, node b) {
  return a.spicy < b.spicy;
}

struct compare{
  bool operator() (const node &a, const int &b) {
    return a.spicy < b;
  }
}; // num을 기준으로 찾기

int main() {
  cin >> n >> q;
  while(n--) {
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end(), cmp);
  while(q--) {
    cin >> a >> b >> x >> y;
    int location = lower_bound(v.begin(), v.end(), a, compare()) - v.begin(), ans = 0;
    for(int i = location; i < v.size() && v[i].spicy <= b; i++) {
      if(x <= v[i].sweet && v[i].sweet <= y) ans++;
    }
    cout << ans << endl;
  }

  return 0;
}