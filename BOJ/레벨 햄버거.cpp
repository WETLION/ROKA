#include <iostream>

// 16974번 레벨 햄버거

using namespace std;


long long n, x, dp[100] = {1}, size[100] ={1};

long long make_dp(int cnt) {
  if(dp[cnt]) return dp[cnt];
  return dp[cnt] = 1 + 2 * make_dp(cnt - 1);
}

long long make_size(int cnt) {
  if(size[cnt]) return size[cnt];
  return size[cnt] = 3 + 2 * make_size(cnt - 1);
}

long long ans(long long ret, long long cnt) {
  x--;
  if(!cnt) return 1;
  if(!x) return ret;
//	cout << x << " " << size[cnt - 1] << endl;
  if(x - size[cnt - 1] < 0) {
    return ans(0, cnt - 1);
  }
  ret += dp[cnt - 1];
  x -= size[cnt - 1];
  if(!x) return ret;
  x--;
  ret++;
  if(!x) return ret;
//	cout << x << " " << size[cnt - 1] << endl;
  if(x - size[cnt - 1] < 0) {
    return ret + ans(0, cnt - 1);
  }
  ret += dp[cnt - 1];
  x -= size[cnt - 1];
  x--;
  return ret;
}

int main() {
  cin >> n >> x;
  make_dp(n);
  make_size(n);
  cout << ans(0, n);
  cin >> n;

  return 0;
} 