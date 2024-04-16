#include <cmath>
#include <iostream>
#include <vector>

// 1089번 스타트링크 타워

using namespace std;

int number, cnt = 1;
long long int sum;
int arr[10][100] /*,
 num[11][11] = {{0, 8},
                {0, 3, 4, 7, 8, 9},
                {2, 8},
                {8, 9},
                {8, 9},
                {6, 8, 9},
                {8},
                {0, 3, 8, 9},
                {8},
                {8, 9},
                {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}},
 num_len[11] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2, 10}*/
    ;
int num_plate[11][5][3] = {
    {{1, 1, 1}, {1, 0, 1}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}},
    {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}},
    {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1}},
    {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}},
    {{1, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {0, 0, 1}},
    {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}},
    {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
    {{1, 1, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}},
    {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
    {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}}/*,
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}*/};

vector<int> v[10] /*, ans*/;

int find_num(int n, int k) {
  // cout << "$$$$$$$$" << k << endl;
  for (int i = 0; i < 5; i++) {
    for (int j = n; j < n + 3; j++) {
      // cout << num_plate[k][i][j - n] << " " << arr[i][j];
      if (num_plate[k][i][j - n] == 0 && arr[i][j] == 1)
        return 0;
    }
    // cout << endl;
  }
  return 1;
}

int what_num(int n, int place) {
  // cout << "#####" << n << endl;
  // vector<int> vv;
  for (int k = 0; k < 10; k++) {
    if (find_num(n, k)) {
      // vv.push_back(k);
      v[place].push_back(k);
    }
  }
  // if (!vv.empty()) {
  //   // int arr[10] = {};
  //   for (int i : vv) {
  //     // cout << "###" << i << endl;
  //     // for (int j = 0; j < num_len[i]; j++) {
  //     //   if(arr[num[i][j]]) continue;
  //     //   arr[num[i][j]] = 1;
  //     v[place].push_back(i);
  //     // }
  //   }
  //   return 1;
  // }
  // return 0;
  return v[place].empty();
}

void num_sum(/*int num*/) {
  // if (num == number) {
  //   // for (int i = 0; i < n; i++) {
  //   //   cout << ans[i];
  //   // }
  //   // cout << "\n";
  //   int make = 0;
  //   for (int i = 0; i < number; i++) {
  //     make += pow(10, i) * ans[number - i - 1];
  //   }
  //   sum += make;
  //   cnt++;
  //   return;
  // }
  for (int i = 0; i < number; i++)
    cnt *= v[i].size();
  for (int i = 0; i < number; i++) {
    int now_sum = 0;
    for (int j : v[i])
      now_sum += j;
    sum += now_sum * pow(10, number - i - 1) * cnt / v[i].size();
    // cout << v[i].size() << " " << now_sum << " " << sum << endl;
    // ans[num] = v[num][i];
    // num_sum(num + 1);
  }
}

int main() {
  // for(int i=0; i<10; i++) {
  //   for(int j=0; j<5; j++) {
  //     for(int k=0; k<3; k++) {
  //       cout << num_plate[i][j][k];
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  // }
  // ios::sync_with_stdio(0);
  // cout.tie(0);
  // cin.tie(0);

  char input;
  cin >> number;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < number * 3 + number - 1; j++) {
      cin >> input;
      arr[i][j] = input == '#' ? 1 : 0;
    }
  }
  for (int i = 0; i < number; i++) {
    if (what_num(4 * i, i)) {
      cout << -1;
      return 0;
    }
  }
  // ans.assign(11, -1);
  num_sum(/*0*/);
  // cout << sum << " " << cnt << endl;
  cout << fixed;
  cout.precision(6);
  cout << (double)sum / cnt;

  return 0;
}