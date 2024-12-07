#include <iostream>
#include <algorithm>
#include <vector>

// 27739번 수열 재배열 

using namespace std;

int n, k, arr[3000], back[3000], front[3000], cnt, ans;
vector<int> v;

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  back[0] = cnt = 1;
  for(int i = 1; i < n - k; i++) {
    if(arr[i - 1] > arr[i]) back[i] = cnt = 1;
    else back[i] = ++cnt;
  }
  front[n - 1] = cnt = 1;
  for(int i = n - 2; i >= k; i--) {
    if(arr[i + 1] < arr[i]) front[i] = cnt = 1;
    else front[i] = ++cnt;
  }
  ans = k;
  // for 범위 오류(i < n - k; => i <= n - k;)
  for(int i = 0; i <= n - k; i++) {
    v.clear();
    for(int j = 0; j < k; j++) {
      v.push_back(arr[i + j]);
    }
    sort(v.begin(), v.end());
    if(i) {
      int location = lower_bound(v.begin(), v.end(), arr[i - 1]) - v.begin();
      ans = max(ans, k - location + back[i - 1]);
    }
    if(i + k < n) {
      int location = lower_bound(v.begin(), v.end(), arr[i + k]) - v.begin();
      ans = max(ans, location + front[i + k]);
    }
    if(i && i + k < n && arr[i - 1] < v.front() && arr[i + k] > v.back()) ans = max(ans, k + back[i - 1] + front[i + k]);
  }
  cout << ans;
  cin >> n;

  return 0;
}