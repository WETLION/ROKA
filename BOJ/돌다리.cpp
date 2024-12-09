#include <iostream>
#include <queue>

// 12761번 돌다리 

using namespace std;

struct node {
  int num, cnt;
};

int a, b, n, m, chk[100001];
queue<node> q;

int main() {
  cin >> a >> b >> n >> m;
  q.push({n, 0});
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    if(now.num == m) {
      cout << now.cnt;
      break;
    }
    now.cnt++;
    if(now.num + 1 <= 100000 && !chk[now.num + 1]) {
      q.push({now.num + 1, now.cnt}); 
      chk[now.num + 1] = 1;
    }
    if(now.num - 1 >= 0 && !chk[now.num - 1]) {
      q.push({now.num - 1, now.cnt});
      chk[now.num - 1] = 1;
    }
    if(now.num + a <= 100000 && !chk[now.num + a]) {
      q.push({now.num + a, now.cnt});
      chk[now.num + a] = 1;
    } 
    if(now.num - a >= 0 && !chk[now.num - a]) {
      q.push({now.num - a, now.cnt});
      chk[now.num - a] = 1;
    } 
    if(now.num + b <= 100000 && !chk[now.num + b]) {
      q.push({now.num + b, now.cnt});
      chk[now.num + b] = 1;
    } 
    if(now.num - b >= 0 && !chk[now.num - b]) {
      q.push({now.num - b, now.cnt});
      chk[now.num - b] = 1;
    }
    if(now.num * a <= 100000 && !chk[now.num * a]) {
      q.push({now.num * a, now.cnt});
      chk[now.num * a] = 1;
    }
    if(now.num * b <= 100000 && !chk[now.num * b]) {
      q.push({now.num * b, now.cnt});
      chk[now.num * b] = 1;
    }
  }
//	cin >> n;

  return 0;
}