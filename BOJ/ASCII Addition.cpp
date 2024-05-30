#include <iostream>
#include <vector>
#include <algorithm>

// 11613번 ASCII Addition

using namespace std;

string number_arr[12][7] =
    {{"xxxxx", "x...x", "x...x", "x...x", "x...x", "x...x", "xxxxx"},
     {"....x", "....x", "....x", "....x", "....x", "....x", "....x"},
     {"xxxxx", "....x", "....x", "xxxxx", "x....", "x....", "xxxxx"},
     {"xxxxx", "....x", "....x", "xxxxx", "....x", "....x", "xxxxx"},
     {"x...x", "x...x", "x...x", "xxxxx", "....x", "....x", "....x"},
     {"xxxxx", "x....", "x....", "xxxxx", "....x", "....x", "xxxxx"},
     {"xxxxx", "x....", "x....", "xxxxx", "x...x", "x...x", "xxxxx"},
     {"xxxxx", "....x", "....x", "....x", "....x", "....x", "....x"},
     {"xxxxx", "x...x", "x...x", "xxxxx", "x...x", "x...x", "xxxxx"},
     {"xxxxx", "x...x", "x...x", "xxxxx", "....x", "....x", "xxxxx"},
     {".....", "..x..", "..x..", "xxxxx", "..x..", "..x..", "....."}},
     arr[20][7];
string input;
int ans, cnt, temp, temp_num;
vector<int> v;

bool what_num(int n, int num) {
  for(int i = 0; i < 7; i++) {
    if(arr[n][i] != number_arr[num][i]) return false;
  }
  return true;
}

int find_num(int n) {
  for (int i = 0; i < 11; i++) {
    if (what_num(n, i)) {
      return i;
    }
  }
  return -1;
}

int main() {
  for (int k = 0; k < 7; k++) {
    cin >> input;
    cnt = 0;
    for(int i = 0; i < input.size(); i++) {
      if(i % 6 == 5) {
        cnt++;
        continue;
      }
      arr[cnt][k] += input[i];
    }
  }
  // for(int k = 0; k < 7; k++) {
  //   for(int i = 0; i <= cnt; i++) {
  //     cout << arr[i][k];
  //   }
  //   cout << endl;
  // }
  for (int i = 0; i <= cnt; i++) {
    temp_num = find_num(i);
    // cout << temp_num << endl;
    if(temp_num == 10) {
      ans += temp;
      temp = 0;
      continue;
    }
    temp = temp * 10 + temp_num;
  }
  ans += temp;
  // cout << ans + temp;
  while(ans) {
    v.push_back(ans % 10);
    ans /= 10;
  }
  reverse(v.begin(), v.end());
  for(int k = 0; k < 7; k++) {
    for(int i = 0; i < v.size(); i++) {
      cout << number_arr[v[i]][k];
      if(i < v.size() - 1) cout << ".";
    }
    cout << endl;
  }

  return 0;
}