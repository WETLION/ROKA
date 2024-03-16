#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef struct {
  int sum, point;
} node;

struct cmp {
  bool operator()(node a, node b) { return a.sum > b.sum; }
};

int way[20][20], ;
priority_queue<node, vector<node>, cmp> pq;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> way[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    pq.push({0, i});
  }

  return 0;
}