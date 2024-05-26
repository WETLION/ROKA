#include <iostream>
#include <algorithm>

// 1676번 팩토리얼 0의 개수

using namespace std;

int n, two, five;

int main() {
  cin >> n;
  for(int i = 2; i <= n; i++) {
    if(!(i % 2)) {
      int temp = i;
      while(!(temp % 2)) {
        two++;
        temp /= 2;
      }
    }
    if(!(i % 5)) {
      int temp = i;
      while(!(temp % 5)) {
        five++;
        temp /= 5;
      }
    }
  }
  cout << min(two, five);

  return 0;
}