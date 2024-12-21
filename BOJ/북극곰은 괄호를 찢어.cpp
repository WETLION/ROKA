#include <iostream>
#include <algorithm>
#include <stack>

// 25918번 북극곰은 괄호를 찢어 

using namespace std;

int n, ans;
string str;
stack<char> s;

int main() {
  cin >> n >> str;
  if(n % 2) {
    cout << -1;
    return 0;
  }
  for(char i: str) {
    if(s.empty()) s.push(i);
    else if(s.top() == i) {
      s.push(i);
    }
    else {
      ans = max(ans, (int)s.size()); // 스택의 최대 깊이여야만 한다? 왜? 
      s.pop();
    }
  }
  if(s.empty()) cout << ans;
  else cout << -1;
  cin >> n;

  return 0;
}