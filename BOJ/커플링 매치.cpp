#include <iostream>
#include <unordered_map>
#include <vector>

// 31908번 커플링 매치

using namespace std;

int n, ans;
string input, name;
unordered_map<string, pair<int, vector<string>>> m;
vector<vector<string>> v;

int main() {
  cin >> n;
  while(n--) {
    cin >> name >> input;
    if (m.find(input) != m.end()) {
      m[input].first++;
      m[input].second.push_back(name);
    } else {
      vector<string> temp;
      temp.push_back(name);
      m.insert({input, {1, temp}});
    }
  }
  for(auto i: m) {
    if(i.first != "-" && i.second.first == 2) {
      ans++;
      v.push_back(i.second.second);
    }
  }
  cout << ans << endl;
  for(vector<string> i: v) {
    for(string j: i) {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}