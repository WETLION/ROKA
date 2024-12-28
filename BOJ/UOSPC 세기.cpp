#include <iostream>
#include <algorithm>

// 30822번 UOSPC 세기

using namespace std;

int n, u, o, s, p, c;
string str;

int main() {
  cin >> n >> str;
  for(char i: str) {
    if(i == 'u') u++;
    else if(i == 'o') o++;
    else if(i == 's') s++;
    else if(i == 'p') p++;
    else if(i == 'c') c++;
  }
  cout << min(u, min(o, min(s, min(p, c))));

  return 0;
}