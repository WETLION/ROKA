#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
  int weight, cost;
} node;

bool cmp(node a, node b) {
  if (a.cost == b.cost)
    return a.weight > b.weight;
  return a.cost < b.cost;
}

vector<node> v;
vector<int> bag;
long long int sum_cost;

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int weight, cost;
    cin >> weight >> cost;
    v.push_back({weight, cost});
  }
  for (int i = 0; i < k; i++) {
    int weight;
    cin >> weight;
    bag.push_back(weight);
  }
  sort(v.begin(), v.end(), cmp);
  sort(bag.begin(), bag.end());
  // for(int i=0; i<n; i++) {
  //   cout << v[i].weight << " " << v[i].cost << endl;
  // }
  // cout << endl;
  // for(int i=0; i<k; i++) {
  //   cout << bag[i] << " ";
  // }
  // cout << endl;
  while (!bag.empty() && !v.empty()) {
    node now = v.back();
    v.pop_back();
    if (now.weight > bag.back())
      continue;
    int lower = lower_bound(bag.begin(), bag.end(), now.weight) - bag.begin();
    cout << "##" << now.weight << " " << bag[lower] << " " << lower << endl;
  }
  cout << sum_cost;

  return 0;
}