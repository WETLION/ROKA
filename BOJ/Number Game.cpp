#include <cstdio>

// 1975번 Number Game

using namespace std;

int t, n, cnt, temp;

int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    cnt = 0;
    for(int i = 2; i <= n; i++) {
      temp = i;
      while(!(n % temp)) {
        cnt++;
        temp *= i;
      }
    }
    printf("%d\n", cnt);
  }

  return 0;
}