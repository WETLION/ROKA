#include <iostream>
#include <vector>
#include <algorithm>

// 1431번 시리얼 번호

using namespace std;

int n;
vector<string> v;
string input;

int is_num(char c) {
  if('0' <= c && c <= '9') return c - '0';
  return -1;
}

int sum_of_num(string w) {
  int sum = 0;
  for(char i: w) {
    int chk = is_num(i);
    if(chk != -1) {
      sum += chk;
    }
  }
  return sum;
}

bool cmp(string a, string b) {
  if(a.size() == b.size()) {
    int na, nb;
    na = sum_of_num(a);
    nb = sum_of_num(b);
    if(na == nb) return a < b;
    return na < nb;
  }
  return a.size() < b.size();
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    v.push_back(input);
  }
  sort(v.begin(), v.end(), cmp);
  for(string i: v) {
    cout << i << endl;
  }
  
  return 0;
}