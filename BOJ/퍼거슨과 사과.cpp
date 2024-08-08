#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// 2942번 퍼거슨과 사과

using namespace std;

long long r, g, gcd, sq, temp;
vector<long long> v;

int _gcd(int a, int b) {
  return a % b ? _gcd(b, a % b) : b;
}

int main() {
  cin >> r >> g;
  gcd = _gcd(max(r, g), min(r, g));
  sq = sqrt(gcd);
  for(int i = 1; i <= sq; i++) {
    if(gcd % i == 0) {
      v.push_back(i);
    }
  }
  // for(int i: v) {
  //   cout << "#" << i << endl;
  // }
  for(int i: v) {
    cout << i << " " << r / i << " " << g / i << endl;
    temp = gcd / i;
    if(temp == i) continue;
    cout << temp << " " << r / temp << " " << g / temp << endl;
  }
  // cout << backup << " " << r / backup << " " << g / backup;

  return 0;
}