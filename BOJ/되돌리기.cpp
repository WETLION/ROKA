#include <iostream>
#include <stack>
#include <unordered_map>

// 1360번 되돌리기

using namespace std;

struct node {
  bool type;
  long long int t;
  char word;
};

unordered_map<long long int, node> m;
stack<long long int> s;
stack<char> ans;

int n;
long long int input_undo, input_time;
string input;
char input_type;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input;
    if (input == "type") {
      cin >> input_type;
      cin >> input_time;
      m.insert({input_time, {0, 0, input_type}});
    } else {
      cin >> input_undo;
      cin >> input_time;
      m.insert({input_time, {1, input_undo, 0}});
    }
    s.push(input_time);
  }
  while (!s.empty()) {
    long long int now = s.top();
    s.pop();
    if (m[now].type) {
      while (!s.empty() && s.top() >= now - m[now].t)
        s.pop();
    } else
      ans.push(m[now].word);
  }
  while (!ans.empty()) {
    char now = ans.top();
    ans.pop();
    cout << now;
  }

  return 0;
}