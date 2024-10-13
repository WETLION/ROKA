#include <iostream>
#include <vector>
#include <algorithm>

// 16496번 큰 수 만들기 

using namespace std;

vector<string> v;
int n;
string input;

bool cmp(string a, string b) {
  if(a.length() == b.length()) return a > b;
  char MAX = 0;
  if(a.length() < b.length()) {
    for(int i = 0; i < b.length(); i++) {
  	  int a_p = i % a.length();
      if(a[a_p] != b[i]) return a[a_p] > b[i];
      MAX = max(MAX, b[i]);
    }
    return b.back() < MAX ? a.back() <= b.back() : a.back() < b.back();
  }
  else {
  	for(int i = 0; i < a.length(); i++) {
  	  int b_p = i % b.length();
      if(a[i] != b[b_p]) return a[i] > b[b_p];
      MAX = max(MAX, b[i]);
    }
    return a.back() < MAX ? a.back() >= b.back() : a.back() > b.back();
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    v.push_back(input);
  }
  sort(v.begin(), v.end(), cmp);
  if(v.front() == "0") {
    cout << 0;
    return 0;
  }
  for(string i: v) {
    cout << i;
  }
  return 0;
}
