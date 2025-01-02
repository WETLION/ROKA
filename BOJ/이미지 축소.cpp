#include <iostream>
#include <algorithm>

// 22994번 이미지 축소 

using namespace std;

int __gcd__(int a, int b) {
  return a % b ? __gcd__(b, a % b) : b;
}

int ni, mj, n, m, nm, mm;
string str[1000];

int main() {
  cin >> ni >> mj;
  for(int i = 0; i < ni; i++) {
    cin >> str[i];
  }
  for(int i = 0; i < ni; i++) {
    int cnt = 1;
    for(int j = 1; j < mj; j++) {
      if(str[i][j - 1] != str[i][j]) {
        if(!mm) mm = cnt;
        else mm = __gcd__(mm, cnt); // 최저값을 사용하는 것이 아니라, 모든 경우의 수에 대해 반드시 최대공약수를 사용해야함. 
        cnt = 1;
      }
      else cnt++;
    }
    mm = __gcd__(mm, cnt); // 모두 같은 경우 cnt를 계산 안함. 이렇게 함으로써 한줄인 경우도 예방 가능. 
  }
  for(int j = 0; j < mj; j++) {
    int cnt = 1;
    for(int i = 1; i < ni; i++) {
      if(str[i - 1][j] != str[i][j]) {
        if(!nm) nm = cnt;
        else nm = __gcd__(nm, cnt); // 최저값을 사용하는 것이 아니라, 모든 경우의 수에 대해 반드시 최대공약수를 사용해야함. 
        cnt = 1;
      }
      else cnt++;
    }
    nm = __gcd__(nm, cnt); // 모두 같은 경우 cnt를 계산 안함. 이렇게 함으로써 한줄인 경우도 예방 가능. 
  }
  n = ni / nm;
  m = mj / mm;
  cout << n << " " << m << endl;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << str[i * nm][j * mm];
    }
    cout << endl;
  }
//	cin >> n;

  return 0;
}