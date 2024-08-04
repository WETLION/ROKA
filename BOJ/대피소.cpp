#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

// 28215번 대피소

using namespace std;

struct node {
  int x, y;
};

int n, k, xx, yy, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, ans = 2000000, len[100][100];
vector<node> v;
vector<int> f;

int find_min(int num) {
  int m = 2000000;
  for(int i: f) m = min(m, len[i][num]);
  return m;
}

void find_ans(int num, int cnt) {
  for(int i = num; i < n; i++) {
    f.push_back(i);
    if(cnt < k) find_ans(i + 1, cnt + 1);
    else {
      int chk[100] = {}, m = 0;
      for(int j: f) chk[j] = -1;
      for(int j = 0; j < n; j++) {
        if(chk[j] == -1) continue;
        m = max(m, find_min(j));
      }
      // for(int j: f) cout << j << " ";
      // cout << m << endl;
      ans = min(ans, m);
    }
    f.pop_back();
  }
}

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> xx >> yy;
    v.push_back({xx, yy});
  }
  for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      len[i][j] = len[j][i] = abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y);
    }
  }
  find_ans(0, 1);
  cout << ans;

  return 0;
}