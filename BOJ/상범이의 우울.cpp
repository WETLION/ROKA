#include <iostream>
#include <algorithm>

// 2811번 상범이의 우울

using namespace std;

int n, MAX, length, ans, arr[100000], MAX_position[50000], MAX_cnt, flower[100000], MAX_flower_cnt;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    if(arr[i] < 0) {
      length++;
    }
    else if(length) {
      if(length > MAX) {
        MAX_position[0] = i - length;
        MAX_cnt = 1;
        MAX = length;
      }
      else if(length == MAX) {
        MAX_position[MAX_cnt++] = i - length;
      }
      for(int j = i - length * 3 < 0 ? 0 : i - length * 3; j < i - length; j++) flower[j] = 1;
      length = 0;
    }
  }
  if(length) {
    if(length > MAX) {
      MAX_position[0] = n - length;
      MAX_cnt = 1;
      MAX = length;
    }
    else if(length == MAX) {
      MAX_position[MAX_cnt++] = n - length;
    }
    for(int j = n - length * 3 < 0 ? 0 : n - length * 3; j < n - length; j++) flower[j] = 1;
  }
  for(int i = 0; i < MAX_cnt; i++) {
    int cnt = 0;
//		cout << MAX << " " << MAX_position[i] << endl;
    for(int j = MAX_position[i] - MAX * 3 < 0 ? 0 : MAX_position[i] - MAX * 3; j < MAX_position[i]; j++) if(!flower[j]) cnt++;
    MAX_flower_cnt = max(MAX_flower_cnt, cnt);
  }
  for(int i = 0; i < n; i++) {
//		cout << flower[i] << " ";
    ans += flower[i];
  }
//	cout << MAX_flower_cnt << endl;
  cout << ans + MAX_flower_cnt;

//	cin >> n;

  return 0;
}