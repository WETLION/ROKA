#include <iostream>
#include <queue>
#include <vector>

// 1240번 노드사이의 거리

using namespace std;

typedef struct {
  int p, sum;
} node;

vector<int> v[1001];

// int len_arr[1001][1001]
int point_arr[1001][1001], n;

// int make_len(int a, int b) {}

int main() {
  int m, a, b, len;
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> len;
    // len_arr[a][b] = len_arr[b][a] =
    point_arr[a][b] = point_arr[b][a] = len;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  // for (int i = 0; i < n; i++) {
  //   for (int j = i + 1; j < n; j++) {
  //     make_len(i, j);
  //   }
  // }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    // cout << len_arr[a][b];
    queue<node> q;
    q.push({a, 0});
    bool visit[1001] = {};
    visit[a] = 1;
    while (!q.empty()) {
      node now = q.front();
      q.pop();
      if (now.p == b) {
        cout << now.sum << "\n";
        break;
      }
      for (int j = 0; j < v[now.p].size(); j++) {
        if (visit[v[now.p][j]])
          continue;
        visit[v[now.p][j]] = 1;
        q.push({v[now.p][j], now.sum + point_arr[now.p][v[now.p][j]]});
      }
    }
  }

  return 0;
}