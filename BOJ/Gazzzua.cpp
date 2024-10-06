#include <iostream>
#include <vector>
#include <algorithm>

// 17939번 Gazzzua

using namespace std;

struct node {
  int num, location;
};

int n, input, sum, cnt, ans;
vector<int> v;
vector<node> vv;

bool cmp(node a, node b) {
  return a.num == b.num ? a.location > b.location : a.num < b.num;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    v.push_back(input);
    vv.push_back({input, i});
  }
  sort(vv.begin(), vv.end(), cmp);
  for(int i = 0; i < n; i++) {
    // cout << v[i] << " " << vv.back().num << " " << ans << " " << cnt << " " << sum << endl;
    if(v[i] == vv.back().num) {
      ans += v[i] * cnt - sum;
      cnt = sum = 0;
      while(!vv.empty() && vv.back().location <= i) vv.pop_back(); //access empty container error => !vv.empty()로 해결
    }
    else {
      sum += v[i];
      cnt++;
    }
  }
  cout << ans;

  return 0;
}