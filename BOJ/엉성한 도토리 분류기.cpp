#include <iostream>
#include <vector>
#include <algorithm>

// 31848번 엉성한 도토리 분류기

using namespace std;

struct node {
  int size, num, order;
};

struct compare{
  bool operator() (const int &a, const node &b) {
    return b.size > a;
  }
};

bool cmp(node a, node b) {
  return a.size < b.size;
}

bool cmp2(node a, node b) {
  return a.order < b.order;
}

int n, q, input, chk;
vector<node> v;
vector<int> hole;

using namespace std;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    hole.push_back(input + i);
  }
  cin >> q;
  for(int i = 0; i < q; i++) {
    cin >> input;
    v.push_back({input, 0, i});
  }
  sort(v.begin(), v.end(), cmp);
  for(int i = 0; i < n; i++) { 
    int location = upper_bound(v.begin(), v.end(), hole[i], compare()) - v.begin();
    if(chk < location) {
      for(int j = chk; j < location; j++) {
        v[j].num = i + 1;
      }
      chk = location;
    }
  }
  sort(v.begin(), v.end(), cmp2);
  for(node i: v) {
    cout << i.num << " ";
  }

  return 0;
}