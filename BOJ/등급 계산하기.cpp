#include <iostream>
#include <vector>
#include <algorithm>

// 25374번 등급 계산하기 

using namespace std;

int n, input, arr[10] = {4, 11, 23, 40, 60, 77, 89, 96, 100}, cnt, ans[10];
vector<int> v;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    v.push_back(input);
  }
  sort(v.begin(), v.end(), greater<int>());
  for(int i = 0; i < 9; i++) {
    while(cnt < n && (cnt > 0 && cnt + 1 > n * arr[i] / 100 && v[cnt - 1] == v[cnt] || cnt + 1 <= n * arr[i] / 100)) {
      ans[i]++;
      cnt++;
    }
  }
  for(int i = 0; i < 9; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}