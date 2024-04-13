#include <algorithm>
#include <iostream>

// 1424번 새 앨범

using namespace std;

int main() {
  int n, l, c, cnt = 1, cd = 0, songs = 0, max_songs = 0;
  cin >> n >> l >> c;
  while (n > 0) {
    if (cd + l <= c) {
      cd += l;
      n--;
      songs++;
      if (cd < c) {
        cd++;
      }
    } else {
      if (songs % 13 == 0) {
        max_songs = songs - 1;
        n++;
      } else
        max_songs = songs;
      cnt++;
      // cout << cnt << " " << cd << " " << songs << " " << songs % 13 << endl;
      cd = 0;
      songs = 0;
    }
  }
  if (songs % 13 == 0 &&
      (cnt == 1 ||
       !(cd + l + 1 <= c && (max_songs - 1) % 13 != 0 ||
         cd + 2 * l + 2 <= c &&
             (max_songs - 2) % 13 != 0))) // and or 연산 우선순위 실수
    cnt++;
  cout << cnt;

  return 0;
}