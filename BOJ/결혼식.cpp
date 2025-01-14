#include <iostream>
#include <vector>
#include <queue>

// 5567번 결혼식

using namespace std;

struct node {
  int num, cnt;
};

queue<node> q;
vector<int> v[501];
int chk[1000], n, m, a, b, ans;

int main() {
  cin >> n >> m;
  q.push({1, 0});
  chk[1] = 1;
  while(m--) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    for(int i: v[now.num]) {
      if(chk[i]) continue;
      if(!now.cnt) q.push({i, 1});
      chk[i] = 1;
      ans++;
    }
  }
  cout << ans;
//	cin >> n;

  return 0;
} 