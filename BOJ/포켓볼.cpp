#include <iostream>
#include <cmath>
#include <algorithm>

// 4030번 포켓볼

using namespace std;

int a, b;

bool permutation(int n) {
  n *= 2;
  int sq = sqrt(n);
  return sq * (sq + 1) == n;
} 

int main() {
  for(int k = 1; ; k++) {
    int cnt = 0;
    cin >> a >> b;
    if(!a && !b) break;
    a = (int)sqrt(a) + 1;
    b = sqrt(b) - ((int)pow((int)sqrt(b), 2) == b);
    for(int i = max((int)2, a); i <= b; i++) {
      int temp = pow(i, 2);
      if(permutation(temp - 1)) cnt++; // temp 대신 i를 넣어버림 
    }
    cout << "Case " << k << ": " << cnt << endl;
  }

  return 0;
} 