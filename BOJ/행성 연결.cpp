#include <algorithm>
#include <iostream>
#include <vector>

// 16398번 행성 연결

using namespace std;

struct node {
  int a, b, price;
};

vector<node> v;
vector<int> connect[1001];
int n, input, arr[1001];
long long int ans;

bool cmp(node a, node b) { return a.price < b.price; }

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    connect[i].push_back(i);
    arr[i] = i;
    for (int j = 0; j <= i; j++) {
      cin >> input;
    }
    for (int j = i + 1; j < n; j++) {
      cin >> input;
      v.push_back({i, j, input});
    }
  }
  sort(v.begin(), v.end(), cmp);
  for (node i : v) {
    if (connect[0].size() == n)
      break;
    if (arr[i.a] == arr[i.b])
      continue;
    ans += i.price;
    if (arr[i.a] > arr[i.b]) {
      for (int j : connect[arr[i.a]]) {
        arr[j] = arr[i.b];
        connect[arr[i.b]].push_back(j);
      }
    } else if (arr[i.a] < arr[i.b]) {
      for (int j : connect[arr[i.b]]) {
        arr[j] = arr[i.a];
        connect[arr[i.a]].push_back(j);
      }
    }
  }
  cout << ans;

  return 0;
}