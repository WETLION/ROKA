#include <iostream>
#include <vector>
#include <algorithm>

// 3231번 카드놀이

using namespace std;

struct node {
  int num, location;
};

bool cmp(node a, node b) {
  return a.num < b.num;
}

vector<node> v;
int n, input, before, ans;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input;
    v.push_back({input, i});
  }
  sort(v.begin(), v.end(), cmp);
  for(node i: v) {
    if(before > i.location) ans++;
    before = i.location;
  }
  cout << ans;

  return 0;
}