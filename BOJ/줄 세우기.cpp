#include <iostream>
#include <vector>
#include <queue>

// 2252번 줄 세우기

using namespace std;

struct node {
  vector<int> v;
  int f, num;
};

bool cmp(node a, node b) {
  return a.f < b.f;
}

int n, m, a, b;
node arr[32001];
queue<node> q;

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    arr[i].num = i + 1;
  }
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    arr[--a].v.push_back(--b);
    arr[b].f++;
  }
  for(int i = 0; i < n; i++) {
    if(!arr[i].f) q.push(arr[i]);
  }
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    cout << now.num << " ";
    for(int i: now.v) {
      if(!(--arr[i].f)) q.push(arr[i]);
    }
  }
//	cin >> n;

  return 0;
} 