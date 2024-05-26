#include <iostream>

// 15829번 Hashing

using namespace std;

int n, r = 31;
long long int m = 1234567891, dp[100] = {1, 31}, ans;
string input;

int main() {
  cin >> n >> input;
  for(int i = 0; i < n; i++) {
    if(i > 1)
      dp[i] = (dp[i - 1] * dp[1]) % m;
    ans += ((input[i] - 'a' + 1) * dp[i]) % m;
  }
  cout << ans % m;

  return 0;
}