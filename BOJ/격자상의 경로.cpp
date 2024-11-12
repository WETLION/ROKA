#include <iostream>

// 10146번 격자상의 경로

using namespace std;

int n, m, k, n_k, m_k;
__int128_t arr[50];

__int128_t factorial(int n) {
  __int128_t ret = 1;
  for(__int128_t i = 2; i <= n; i++) ret *= i;
  return ret;
}

ostream &operator<<(ostream &dest, __int128_t value) {
  ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(ios_base::badbit);
    }
  }
  return dest;
}

int main() {
  cout << fixed;
  cout.precision(0);
  for(int i = 0; i <= 30; i++) {
    arr[i] = factorial(i);
  }
  cin >> n >> m >> k;
  if(!k) {
    cout << arr[--n + --m] / arr[n] / arr[m];
  } else {
    n_k = k / m;
    m_k = k % m - 1;
    if(k % m == 0) {
      if(n_k >= 1) n_k--; // > 1 -> >= 1 
      m_k += m;
    }
//		cout << n_k << " " << m_k << endl; 
    cout << arr[n_k + m_k] / arr[n_k] / arr[m_k] * arr[--n - n_k + --m - m_k] / arr[n - n_k] / arr[m - m_k];
  }

  return 0;
}