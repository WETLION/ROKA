#include <iostream>
#include <algorithm>
#include <vector>

// 25577번 열 정렬정렬 정 

using namespace std;

struct node {
  int num, location;
};

int n, input, cnt;
vector<node> v, vv;

bool cmp(node a, node b) {
  return a.num < b.num;
}

struct compare{
  bool operator() (const node &a, const int &b) {
    return a.num < b;
  }
};

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    v.push_back({input, i});
  }
  vv = v;
  sort(v.begin(), v.end(), cmp);
  for(int i = 0; i < n; i++) {
    if(v[i].location == i) continue;
    cnt++;
    int location = lower_bound(v.begin(), v.end(), vv[i].num, compare()) - v.begin();
    v[location].location = v[i].location;
    node t_vv = vv[i];
    vv[i] = vv[v[i].location];
    vv[v[i].location] = t_vv;
  }
  cout << cnt;

  return 0;
}