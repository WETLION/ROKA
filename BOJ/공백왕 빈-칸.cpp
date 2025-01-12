#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// 3518번 공백왕 빈-칸 

using namespace std;

vector<string> arr[1000];
string str;
int cnt[180], n;

int main() {
  for(; ; n++) {
    getline(cin, str);
    if(cin.eof()) break;
//		if(str == "0") break; 
    string temp;
    for(char i: str) {
      if(i == ' ') {
        if(temp.empty()) continue;
        else {
          cnt[arr[n].size()] = max(cnt[arr[n].size()], int(temp.size()));
          arr[n].push_back(temp);
          temp.clear();
        }
      }
      else temp += i;
    }
    if(!temp.empty()) {
      cnt[arr[n].size()] = max(cnt[arr[n].size()], int(temp.size()));
      arr[n].push_back(temp);
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j];
      if(j == arr[i].size() - 1) break; // 띄어쓰기 이슈(마지막 단어인 경우) 
      for(int k = arr[i][j].size(); k <= cnt[j]; k++) cout << ' ';
    }
    cout << endl;
  }
//	cin >> str;

  return 0;
}