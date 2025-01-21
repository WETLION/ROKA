#include <iostream>
#include <algorithm>

// 25916번 싫은데요 

using namespace std;

int n, m, arr[500000], sum, ans, f, b;

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  while(b < n) {
    sum += arr[b++];
    while(sum > m) sum -= arr[f++];
    ans = max(ans, sum);
  }
  cout << ans;
//	cin >> n;

  return 0;
}