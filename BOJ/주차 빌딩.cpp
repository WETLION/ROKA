#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// 3699번 주차 빌딩

using namespace std;

struct node {
  int num, location, location_h;
};

bool cmp(node a, node b) {
  return a.num < b.num;
}

int t, h, l, input, status, ans;
vector<node> v;
vector<int> arr;

int main() {
  cin >> t;
  while(t--) {
    ans = status = 0;
    v.clear();
    arr.clear();
    cin >> h >> l;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < l; j++) {
        cin >> input;
        if(input > 0) {
          v.push_back({input, j, i});
          // cout << input << " " << j << endl;
          ans += 20 * i;
        }
      }
      arr.push_back(0);
    }
    sort(v.begin(), v.end(), cmp);
    // cout << "@" << v.size() << endl;
    for(node i: v) {
      int diff = i.location - arr[i.location_h];
      ans += (abs(diff) <= l / 2 ? abs(diff) : l - abs(diff)) * 5;
      // cout << "#" << i.location << " " << status << " " << diff << " " << l - diff << endl;
      arr[i.location_h] = (arr[i.location_h] + diff) % l;
    }
    cout << ans << endl;
  }


  return 0;
}