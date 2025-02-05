#include <iostream>
#include <string>

// 1992번 쿼드트리 

using namespace std;

int n, dx[4] = {0, 1, 0, 1}, dy[4] = {0, 0, 1, 1};
string map[100];

char split_check(int len, int x, int y) {
  for(int i = 0; i < len; i++) {
    for(int j = 0; j < len; j++) {
      if(map[y][x] != map[y + i][x + j]) return 0; 
    }
  }
  return map[y][x];
}

string make_quad_tree(int now, int x, int y) { // 전부 같은 숫자의 경우 4개의 숫자가 아니라 1개의 숫자만 출력되어야함. 비압축이므로 괄호도 포함되면 안됨. 
  char chk = split_check(now, x, y);
  if(chk != 0) return to_string(chk - '0');
  string ret = "(";
  now /= 2;
  for(int k = 0; k < 4; k++) {
    int xx = x + dx[k] * now, yy = y + dy[k] * now;
    char cmp = split_check(now, xx, yy);
    if(!cmp) ret += make_quad_tree(now, xx, yy);
    else ret += cmp;
  }
  return ret + ")";
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> map[i];
  }
  cout << make_quad_tree(n, 0, 0);
  cin >> n;

  return 0;
}