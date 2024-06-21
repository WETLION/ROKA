#include <iostream>

// 1247번 부호

using namespace std;

int n;
long long int input;

int main() {
  for(int i = 0; i < 3; i++) {
    __int128_t sum = 0;
    cin >> n;
    while(n--) {
      cin >> input;
      sum += input;
    }
    if(sum < 0) cout << '-' << endl;
    else if (sum == 0) cout << 0 << endl;
    else cout << '+' << endl;
  }

  return 0;
}