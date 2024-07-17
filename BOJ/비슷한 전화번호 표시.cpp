#include <iostream>
#include <sstream>

// 26041번 비슷한 전화번호 표시

using namespace std;

string a, b, i;
int cnt;

bool cmp() {
  for(int j = 0; j < b.size(); j++) {
    if(i[j] != b[j]) return 0;
  }
  return 1;
}

int main() {
  getline(cin, a);
  cin >> b;
  stringstream ss;
  ss.str(a);
  while(ss >> i){
    if(i.size() < b.size() || i == b) continue;
    cnt += cmp();
  }
  cout << cnt;

  return 0;
}