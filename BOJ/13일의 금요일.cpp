#include <iostream>

// 16463번 13일의 금요일

using namespace std;

int y = 2019, m = 1, d = 4, m_d[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, target, cnt;

int main() {
  cin >> target;
  while(target >= y) {
    d += 7;
    if(d == 13) {
      cnt++;
      continue;
    }
    if(y % 400 == 0 || y % 100 != 0 && y % 4 == 0) {
      if(m == 2 && d > 29) {
        m = 3;
        d -= 29;
      }
      else if(m != 2 && d > m_d[m]) {
        d -= m_d[m++];
        if(m > 12) {
          y++;
          m = 1;
        }
      }
    }
    else if(d > m_d[m]) {
      d -= m_d[m++];
      if(m > 12) {
        y++;
        m = 1;
      }
    }
  }
  cout << cnt;

  return 0;
}