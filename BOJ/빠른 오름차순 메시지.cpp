#include <iostream>
#include <queue>
#include <algorithm>

// 25824번 빠른 오름차순 메시지 

using namespace std;

struct node {
  int now, cnt, sum;
};

int arr[15][15], ans = 100000000;
queue<node> q;

int main() {
  for(int i = 0; i < 12; i++) {
    for(int j = 0; j < 12; j++) {
      cin >> arr[i][j];
    }
  }
  q.push({0, 1, 0});
  q.push({1, 1, 0});
  while(!q.empty()) {
    node now = q.front();
    q.pop();
//		cout << now.now << " " << now.cnt << " " << now.sum << endl;
    if(now.cnt == 12) {
      ans = min(ans, now.sum);
      continue;
    }
    if(now.cnt % 2) {
      if(now.now % 2) q.push({now.now - 1, now.cnt + 1, now.sum + arr[now.now][now.now - 1]});
      else q.push({now.now + 1, now.cnt + 1, now.sum + arr[now.now][now.now + 1]});
    }
    else {
      q.push({now.now + 1 + !(now.now % 2), now.cnt + 1, now.sum + arr[now.now][now.now + 1 + !(now.now % 2)]});
      q.push({now.now + 2 + !(now.now % 2), now.cnt + 1, now.sum + arr[now.now][now.now + 2 + !(now.now % 2)]});
    }
  }
  cout << ans;

  return 0;
}