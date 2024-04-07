#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

// 1939번 중량제한

using namespace std;

typedef struct {
  int point, weight;
} node;

queue<node> q;
vector<node> v[10001];

int arr[10001];

bool cmp(node a, node b) { return a.weight > b.weight; }

int main() {
  int n, m, a, b, weight, start, finish;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> weight;
    v[a].push_back({b, weight});
    v[b].push_back({a, weight});
  }
  cin >> start >> finish;
  for (int i = 1; i <= n; i++) {
    sort(v[i].begin(), v[i].end(), cmp);
  }
  for (node i : v[start]) {
    q.push(i);
  }
  while (!q.empty()) {
    node now = q.front();
    q.pop();
    //		cout << now.point << " " << now.weight << endl;
    if (arr[now.point] <= now.weight) {
      arr[now.point] = now.weight;
      if (now.point == finish)
        continue;
      for (node i : v[now.point]) {
        if (arr[i.point] < min(now.weight, i.weight)) {
          arr[i.point] = min(now.weight, i.weight);
          if (i.weight <= now.weight)
            q.push(i);
          else
            q.push({i.point, now.weight});
        }
      }
    }
  }
  cout << arr[finish];
  //	cin >> finish; // dev error fix

  return 0;
}