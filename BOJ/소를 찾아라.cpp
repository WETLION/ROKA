#include <iostream>
#include <vector>
#include <algorithm>

// 5874번 소를 찾아라

using namespace std;

int cnt;
string input;
vector<int> f, b;

int main() {
  cin >> input;
  for(int i = 0; i < input.size() - 1; i++) {
    if(input[i] == input[i + 1]) {
      if(input[i] == '(') {
        f.push_back(i);
      }
      else {
        b.push_back(i);
      }
    }
  }
  for(int i: f) {
    int location = upper_bound(b.begin(), b.end(), i) - b.begin();
    if(location == b.size()) continue;
    cnt += b.size() - location;
  }
  cout << cnt;

  return 0;
}