#include <iostream>
#include <string>
#include <algorithm>

// 20164번 홀수 홀릭 호석

using namespace std;

string n;

string split(string str, int a, int b) {
//	cout << stoi(str.substr(0, a)) << " " << stoi(str.substr(a, b - a)) << " " << stoi(str.substr(b, str.size() - b)) << endl;
  return to_string(stoi(str.substr(0, a)) + stoi(str.substr(a, b - a)) + stoi(str.substr(b, str.size() - b)));
}

string make_ans(string str) {
  if(str.size() == 1) {
    int temp = str[0] % 2; // 까먹고 '0' 더하는 지점 안 없앰 
//		cout << "!" << temp << endl;
    return to_string(temp) + " " + to_string(temp); // to_string 붙이니 해결, char에서 바로 string 전환은 안되는듯. 
  }
  if(str.size() == 2) {
    int temp = str[0] % 2 + str[1] % 2;
//		cout << temp << endl;
    if(str[0] + str[1] - '0' * 2 > 9) temp += make_ans(to_string(str[0] + str[1] - '0' * 2))[0] - '0'; // 두 자리 숫자의 자리수를 더해서 두 자리가 나오는 경우를 포함 안함 
    else temp += (str[0] + str[1]) % 2;
    return to_string(temp) + " " + to_string(temp); // to_string 붙이니 해결, char에서 바로 string 전환은 안되는듯. 
  }
  int cnt = 0, MAX = 0, MIN = 999999999;
  for(char i: str) {
    cnt += (i - '0') % 2;
  }
  for(int i = 1; i < str.size() - 1; i++) {
    for(int j = i + 1; j < str.size(); j++) {
      string after = make_ans(split(str, i, j));
      int after_MAX, after_MIN;
//			cout << after << endl;
      for(int i = 0; i < after.size(); i++) {
        if(after[i] == ' ') {
          after_MIN = stoi(after.substr(0, i)); // 슬라이싱 개수 오류 i + 1 => i 
          after_MAX = stoi(after.substr(i + 1, after.size() - i - 1)); // 슬라이싱 개수 오류 after.size() - i => after.size() - i - 1 
//					cout << "#" << after_MIN << endl;
          break;
        }
      }
      MAX = max(MAX, after_MAX);
      MIN = min(MIN, after_MIN);
    }
  }
  return to_string(cnt + MIN) + " " + to_string(cnt + MAX);
}

int main() {
  cin >> n;
  cout << make_ans(n);
  cin >> n;

  return 0;
} 