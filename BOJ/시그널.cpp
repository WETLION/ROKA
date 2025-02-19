#include <iostream>

// 16113번 시그널

using namespace std;

string word[20][10] = {{"###", "#.#", "#.#", "#.#", "###"}, {"#", "#", "#", "#", "#"}, {"###", "..#", "###", "#..", "###"}, {"###", "..#", "###", "..#", "###"}, {"#.#", "#.#", "###", "..#", "..#"}, {"###", "#..", "###", "..#", "###"}, {"###", "#..", "###", "#.#", "###"}, {"###", "..#", "..#", "..#", "..#"}, {"###", "#.#", "###", "#.#", "###"}, {"###", "#.#", "###", "..#", "###"}}, str, arr[5], ans;
int n;

bool isit_1(int start) { // true false 반대로 검 
  if(start == n / 5 - 1) return true; // n - 1이 아니고 n / 5 - 1이 끝임.. 
  for(int i = 0; i < 5; i++) {
    if(arr[i][start] != '#' || arr[i][start + 1] != '.') return false;
  }
  return true;
}

bool isit_num(int start, int num) {
//	cout << "#" << start << ' ' << num << endl;
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 3; j++) {
//			cout << word[num][i][j] << ' ' << arr[i][start + j] << ' ';
      if(word[num][i][j] != arr[i][start + j]) return false;
    }
//		cout << endl;
  }
  return true;
}

int make_num(int start) {
  if(isit_1(start)) {
    ans += '1';
    return 1;
  }
  for(int i = 0; i < 10; i++) {
    if(i == 1) continue;
    if(isit_num(start, i)) {
      ans += i + '0';
      break;
    }
  }
  return 3;
}

int main() {
//	for(int i = 0; i < 10; i++) {
//		for(int j = 0; j < 5; j++) {
//			cout << word[i][j] << endl;
//		}
//	}
  cin >> n >> str;
  for(int i = 0; i < 5; i++) {
    arr[i] = str.substr(i * n / 5, n / 5);
//		cout << arr[i] << endl;
  }
//	cout << endl;
  for(int i = 0; i < n / 5; i++) {
    if(arr[0][i] == '#') {
//			cout << '$' << i << endl;
      i += make_num(i);
    }
  }
  cout << ans;
  cin >> n;

  return 0;
} 