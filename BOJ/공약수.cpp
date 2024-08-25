#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

// 2436번 공약수

using namespace std;

int gcd, lcm, sqrt_lcm, before, MIN, a, b;
vector<int> v;

int _gcd(int a, int b) {
  return a % b ? _gcd(b, a % b) : b;
}

int main() {
  cin >> gcd >> lcm;
  MIN = gcd + lcm;
  a = gcd;
  b = lcm;
  lcm /= gcd;
  sqrt_lcm = (int)sqrt(lcm);
  for(int i = 2; i <= sqrt_lcm; i++) {
    if(lcm % i == 0 && _gcd(lcm / i, i) == 1){
      // if(i + lcm / i < MIN){
      //   MIN = i + lcm / i;
      //   a = i;
      //   b = lcm / i;
      // }
      v.push_back(i);
      v.push_back(lcm / i);
    }
  }
  sort(v.begin(), v.end());
  // for(int i: v) {
  //   cout << i << " ";
  // }
  // cout << endl;
  // cout << a * gcd << " " << b * gcd; 
  if(v.empty()) cout << gcd << " " << lcm * gcd; // lcm이 gcd의 제곱수일 경우 벡터가 비어있음 <- 이걸 빼먹음
  else cout << v[v.size() / 2 - 1] * gcd << " " << v[v.size() / 2] * gcd;

  return 0;
}