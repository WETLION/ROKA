#include <iostream>

// 14646번 욱제는 결정장애야!! 

using namespace std;

int n, arr[100001], ans, input, cnt;

int main() {
  cin >> n;
  for(int i = 0; i < 2 * n; i++) {
    cin >> input;
    ans = max(ans, cnt += arr[input]++ ? -1 : 1);
  }
  cout << ans;

  return 0;
}