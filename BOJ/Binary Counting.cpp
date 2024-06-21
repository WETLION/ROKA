#include <iostream>
#include <cmath>

// 15876번 Binary Counting

using namespace std;

int k, n, cnt, bin;

int main() {
  cin >> n >> k;
  while(1) {
    for(int i = bin != 0 ? log2(bin) : 0; i >= 0; i--) {
      // cout << "#" << i << ' ' << bin << endl;
      if(cnt == n * 5) return 0;
      if(cnt++ % n == k - 1) {
        cout << ((bin >> i) & 1) << ' ';
      }
    }
    bin++;
  }

  return 0;
}