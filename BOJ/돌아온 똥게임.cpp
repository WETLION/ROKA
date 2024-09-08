#include <iostream>
#include <vector>
#include <algorithm>

// 30701번 돌아온 똥게임

using namespace std;

int cnt;
long long n, di, ai, xi;
__int128_t d;
vector<__int128_t> v1, v2;

int main() {
  cin >> n >> di;
  d = di;
  for(int i = 0; i < n; i++) {
    cin >> ai >> xi;
    if(ai == 1) v1.push_back(xi);
    else v2.push_back(xi);
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end(), greater<__int128_t>());
  for(__int128_t i: v1) {
    // cout << d << " " << i << endl;
    if(d <= i) {
      while(!v2.empty() && d <= i){
        d *= v2.back();
        v2.pop_back();
        cnt++;
      }
      if(d <= i) break;
    }
    d += i;
    cnt++;
  }
  cout << cnt + v2.size();

  return 0;
}