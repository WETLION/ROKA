#include <iostream>
#include <algorithm>
#include <vector>

// 7568번 덩치

using namespace std;

struct node {
  int height, weight, rank;
};

int n, input_h, input_w;
vector<node> v;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input_w >> input_h;
    v.push_back({input_w, input_h, 1});
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(v[i].height < v[j].height && v[i].weight < v[j].weight) v[i].rank++;
    }
  }
  for(node i: v) {
    cout << i.rank << " ";
  }

  return 0;
}