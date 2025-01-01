#include <iostream>
#include <unordered_map>

// 14425번 문자열 집합 

using namespace std;

unordered_map<string, int> um;
string str;
int n, m, ans;

int main() {
  cin >> n >> m;
  while(n--) {
    cin >> str;
    um.insert({str, 1});
  }
  while(m--) {
    cin >> str;
    if(um.find(str) != um.end()) ans++;
  }
  cout << ans;

  return 0;
}