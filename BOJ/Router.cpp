#include <iostream>
#include <queue>

// 15828번 Router

using namespace std;

queue<int> q;
int n, input;

int main() {
  cin >> n;
  while(1) {
    cin >> input;
    if(input == -1) break;
    if(input == 0) q.pop();
    else if(q.size() < n) q.push(input);
  }
  if(q.empty()) cout << "empty";
  else {
    while(!q.empty()) {
      cout << q.front() << " ";
      q.pop();
    }
  }

  return 0;
}