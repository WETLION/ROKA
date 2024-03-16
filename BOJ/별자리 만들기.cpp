#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
  int f, b;
  double cost;
} node;

struct cmp {
  bool operator()(node &a, node &b) { return a.cost > b.cost; }
};

vector<int> v[101];
priority_queue<node, vector<node>, cmp> pq;

int arr[101];
double point[101][2], cost[101];

int main() {
  int n, f, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> point[i][0] >> point[i][1];
    arr[i] = i;
    v[i].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      pq.push({i, j,
               sqrt(pow(abs(point[i][0] - point[j][0]), 2) +
                    pow(abs(point[i][1] - point[j][1]), 2))});
    }
  }
  while (!pq.empty()) {
    if (v[0].size() == n)
      break;
    node now = pq.top();
    pq.pop();
    int in, out;
    f = now.f;
    b = now.b;
    // cout << "##" << f << " " << b << " " << now.cost << endl;
    if (arr[f] == arr[b])
      continue;
    if (arr[f] > arr[b]) {
      in = arr[b];
      out = arr[f];
    } else {
      in = arr[f];
      out = arr[b];
    }
    cost[in] += cost[out] + now.cost;
    while (!v[out].empty()) {
      int temp = v[out].back();
      v[out].pop_back();
      v[in].push_back(temp);
      arr[temp] = in;
    }
    // cout << endl;
    // for(int j=0; j<n; j++) {
    //   cout << arr[j] << " " << cost[j] << endl;
    // }
  }
  cout << cost[0];

  return 0;
}