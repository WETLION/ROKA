#include <iostream>
#include <vector>
#include <algorithm>

// 24483번 알고리즘 수업 

using namespace std;

int n, m, r, visit[100001], u, v;
long long ans, time; // 오버플로우 방지 
vector<int> arr[100001];

void dfs(int num, long long depth) { // 오버플로우 방지 
  visit[num] = 1;
  ans += depth * ++time;
  for(int i: arr[num]) {
    if(visit[i]) continue;
    dfs(i, depth + 1);
  }
}

int main() {
  cin >> n >> m >> r;
  for(int i = 0; i < m; i++) {
    cin >> u >> v;
    arr[u].push_back(v);
    arr[v].push_back(u); // 무방향 그래프 고려 안함 
  }
  for(int i = 1; i <= n; i++) {
    sort(arr[i].begin(), arr[i].end());
  }
  dfs(r, 0);
  cout << ans;

  return 0;
}