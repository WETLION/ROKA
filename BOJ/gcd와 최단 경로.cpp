#include <iostream>

// 32632번 gcd와 최단 경로 

using namespace std;

int n, k, ans;

int __gcd__(int a, int b) {
  int mod = a % b;
  return mod ? __gcd__(b, mod) : b;
}

int main() {
  cin >> k >> n;
  for(int i = 1; i <= n; i++) { // 조건 범위 오류 (< -> <=) 
    if(i == k) continue; // n == k 오류 
    int gcd = __gcd__(k, i);
//		cout << gcd << endl;
    if(gcd == 1 || gcd == 2) ans++;
  }
  cout << ans;
//	cin >> n;

  return 0;
}