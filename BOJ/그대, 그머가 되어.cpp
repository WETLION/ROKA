#include <iostream>
#include <queue>
#include <vector>

//14496번 그대, 그머가 되어 

using namespace std;

struct node {
  int num, cnt;
};

int n, m, chk[1001], a, b, s, f;
queue<node> q;
vector<int> v[1001];

int main() {
  cin >> s >> f >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  q.push({s, 0});
  chk[s] = 1;
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    if(now.num == f) {
      cout << now.cnt;
      return 0;
    }
    for(int i: v[now.num]) {
      if(!chk[i]) {
        chk[i] = 1;
        q.push({i, now.cnt + 1});
      }
    }
  }
  cout << -1;

  return 0;
}