#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

// 1764번 듣보잡

using namespace std;

int n, m;
string input;
unordered_map<string, int> um;
vector<string> v;

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> input;
    um.insert({input, 1});
  }
  for(int i = 0; i < m; i++) {
    cin >> input;
    if(um.find(input) != um.end()) {
      v.push_back(input);
    }
  }
  cout << v.size() << endl;
  sort(v.begin(), v.end());
  for(string i: v) {
    cout << i << "\n";
  }

  return 0;
}