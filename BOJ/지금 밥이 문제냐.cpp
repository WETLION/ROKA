#include <iostream>

// 12787번 지금 밥이 문제냐

using namespace std;

unsigned long long int t, n, m;
string ip;

void push_bit(int num) {
  for(int i = 7; i >= 0; i--) {
    // cout << ((num >> i) & 1);
    m <<= 1;
    m = m | (num >> i) & 1;
    // cout << m << " ";
    // cout << m << endl;
  }
  // cout << endl;
}

int main() {
  cin >> t;
  while(t--) {
    cin >> n;
    if(n == 1) {
      m = 0;
      cin >> ip;
      int num = 0;
      for(char i: ip) {
        if(i == '.') {
          push_bit(num);
          num = 0;
        }
        else num = num * 10 + i - '0';
      }
      push_bit(num);
      cout << m << endl;
    } 
    else {
      cin >> m;
      int num = 0;
      for(int i = 63; i >= 0; i--) {
        num <<= 1;
        num = num | (m >> i) & 1;
        if(i && i % 8 == 0) {
          cout << num << ".";
          num = 0;
        }
      }
      cout << num << endl;
    }
  }

  return 0;
}