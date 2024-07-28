#include <iostream>

// 2748번 피보나치 수 2

using namespace std;

int n;
long long dp[100] = {0, 1, 1};

long long fibo(int num) {
  if(dp[num]) return dp[num]; 
  return dp[num] = fibo(num - 1) + fibo(num - 2);
}

int main() {
  cin >> n;
  cout << fibo(n);

  return 0;
}