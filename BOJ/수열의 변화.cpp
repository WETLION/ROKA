#include <iostream>
#include <string>
#include <vector>

// 1551번 수열의 변화

using namespace std;

int n, k;
string str, sti;
vector<int> v;

int main() {
  cin >> n >> k >> str;
  for(char i: str) {
    if(i == ',') {
      v.push_back(stoi(sti));
      sti.clear();
    }
    else sti += i;
  }
  v.push_back(stoi(sti));
  while(k--) {
    vector<int> temp;
    for(int i = 1; i < v.size(); i++) {
      temp.push_back(v[i] - v[i - 1]);
    }
    v = temp;
  }
  for(int i = 0; i < v.size() - 1; i++) {
    cout << v[i] << ',';
  }
  cout << v.back();

  return 0;
}