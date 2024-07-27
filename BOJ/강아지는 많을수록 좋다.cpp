#include <iostream>
#include <queue>

// 27971번 강아지는 많을수록 좋다

using namespace std;

struct node {
  int num, cnt;
};

int n, m, a, b, chk[100001], s, f, ans;
queue<node> q;

int main() {
  cin >> n >> m >> a >> b;
  while(m--) {
    cin >> s >> f;
    for(int i = s; i <= f; i++) {
      chk[i] = 1;
    }
  }
  if(!chk[a]) q.push({a, 1});
  if(!chk[b]) q.push({b, 1});
  chk[a] = chk[b] = 1;
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    if(now.num == n) {
      cout << now.cnt;
      return 0;
    }
    if(now.num + a <= n && !chk[now.num + a]) {
      q.push({now.num + a, now.cnt + 1});
      chk[now.num + a] = 1;
    }
    if(now.num + b <= n && !chk[now.num + b]) {
      q.push({now.num + b, now.cnt + 1});
      chk[now.num + b] = 1;
    }
  }
  cout << -1;

  return 0;
}