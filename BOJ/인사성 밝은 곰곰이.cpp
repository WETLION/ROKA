#include <iostream>
#include <set>
#include <cstdio>

// 25192번 인사성 밝은 곰곰이

using namespace std;

int n, chk, cnt;
string input;
set<string> s;

int main() {
  cin >> n;
  while(n--) {
    cin >> input;
    if(input == "ENTER") {
      chk = 1;
      s.clear();
    }
    else if(chk && s.find(input) == s.end()) {
      s.insert(input);
      cnt++;
    }
  }
  cout << cnt;

  return 0;
}