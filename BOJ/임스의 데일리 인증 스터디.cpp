#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// 29730번 임스의 데일리 인증 스터디

using namespace std;

int n;
vector<string> v;
vector<int> num;
string input;

bool cmp(string a, string b) {
  return a.length() == b.length() ? a < b : a.length() < b.length();
}

int main() {
  cin >> n;
  getchar();
  while(n--) {
    getline(cin, input);
    if(input.length() > 7 && input[6] == '/') {
      int sum = 0;
      for(int i = 7; i < input.length(); i++) {
        sum = sum * 10 + input[i] - '0';
      }
      num.push_back(sum);
    }
    else v.push_back(input);
  }
  sort(num.begin(), num.end());
  sort(v.begin(), v.end(), cmp);
  for(string i: v) cout << i << endl;
  for(int i: num) cout << "boj.kr/" << i << endl;

  return 0;
}