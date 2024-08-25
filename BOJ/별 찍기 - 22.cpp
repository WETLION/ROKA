#include <iostream>

// 10997번 별 찍기 - 22

using namespace std;

int n, arr[500][500], cnt = 2, way = 0; // up, right, down, left => 0, 1, 2, 3
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

int main() {
  cin >> n;
  if(n == 1) {
    cout << "*";
    return 0;
  }
  int i = 2 * n, j = 2 * n - 2;
  while(cnt <= 4 * n + 1) {
    for(int temp = 0; temp < cnt; i = i + dy[way], j = j + dx[way], temp++) {
      arr[i][j] = 1;
      // cout << i << " " << j << endl;
    }
    way = (way + 1) % 4;
    if(way == 0 || way == 2) cnt += 2;
  }
  for(i = 0; i < 4 * n - 1; i++) {
    if(i == 1) {
      cout << '*' << endl; // 두번째 줄 우측 공백은 출력되면 안됨..
      continue;
    }
    for(j = 0; j < 4 * n - 3; j++) {
      cout << (arr[i][j] ? '*' : ' ');
    }
    cout << '\n';
  }

  return 0;
}