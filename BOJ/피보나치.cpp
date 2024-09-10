#include <iostream>
#include <vector>
#include <algorithm>

// 9009번 피보나치

using namespace std;

int n, t;
vector<int> fibo;

int main() {
  fibo.push_back(0);
  fibo.push_back(1);
  for(int i = 2; fibo[i - 1] + fibo[i - 2] <= 1000000000; i++) {
    fibo.push_back(fibo[i - 1] + fibo[i - 2]);
  }
  cin >> t;
  while(t--) {
    vector<int> v;
    cin >> n;
    while(n > 0) {
      int num = *(upper_bound(fibo.begin(), fibo.end(), n) - 1);
      // cout << n << " " << num << endl;
      n -= num;
      v.push_back(num);
    }
    while(!v.empty()) {
      cout << v.back() << " ";
      v.pop_back();
    }
    cout << endl;
  }

  return 0;
}