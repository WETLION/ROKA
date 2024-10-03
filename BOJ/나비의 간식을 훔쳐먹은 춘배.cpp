#include <iostream>
#include <queue>
#include <algorithm>

// 30407번 나비의 간식을 훔쳐먹은 춘배

using namespace std;

struct node {
  int h, d, cnt, chk;
};

int n, k, arr[30], ans = -1;
node input;
queue<node> q;

int main() {
  cin >> n;
  cin >> input.h >> input.d >> k;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  q.push(input);
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    // cout << now.cnt << " " << now.h << " " << now.d << " " << now.chk << endl;
    if(now.cnt == n) {
      ans = max(ans, now.h);
      continue;
    }
    now.cnt++;
    if(now.chk == 1) {
      now.d += k;
      now.chk++;
      q.push(now);
    }
    else {
      int damage = arr[now.cnt] - now.d;
      if(damage < 0) damage = 0;
      if(now.h - damage / 2 > 0) q.push({now.h - damage / 2, now.d, now.cnt, now.chk});
      if(now.h - damage > 0 && !now.chk) q.push({now.h - damage, now.d, now.cnt, 1});
      damage -= k;
      if(damage < 0) damage = 0;
      if(now.h - damage > 0) q.push({now.h - damage, now.d + k, now.cnt, now.chk});
    }
  }
  cout << ans;

  return 0;
}