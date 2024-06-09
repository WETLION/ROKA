#include <iostream>
#include <vector>
#include <algorithm>

// 29808번 너의 수능 점수가 궁금해

using namespace std;

long long int s;
vector<pair<int, int>> v;

int main() {
  cin >> s;
  if(s % 4763 != 0) {
    cout << 0;
    return 0;
  }
  s /= 4763;
  for(int i = 0; i <= 200; i++) {
    long long int kor = i * 508, eng = i * 108;
    for(int j = 0; j <= 200; j++) {
      long long int math = j * 212, tam = j * 305;
      if(kor + math == s || kor + tam == s || eng + math == s || eng + tam == s) {
        v.push_back({i, j});
      }
    }
  }
  cout << v.size();
  for(auto i: v) {
    cout << endl << i.first << " " << i.second;
  }

  return 0;
}