#include <iostream>
#include <vector>
#include <algorithm>

// 1654번 랜선 자르기

using namespace std;

long long int n, k, input, ans, low, high;
vector<int> v;

int main() {
  cin >> k >> n;
  for(int i = 0; i < k; i++) {
    cin >> input;
    v.push_back(input);
    high = max(high, input);
  }
  while(low <= high) { // 0이나 최댓값 미출력 해결을 위해 <=으로 수정
    long long int mid = (high + low) / 2, sum = 0;
    if(mid == 0) mid = 1; // Division By Zero 해결
    for(int i: v) {
      sum += i / mid;
    }
    if(sum >= n) {
      ans = mid;
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }
  cout << ans;

  return 0;
}