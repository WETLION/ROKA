#include <iostream>
#include <vector>

// 1411번 비슷한 단어 

using namespace std;

int n, cnt[200][100], ans;
string str[200];

void make_cnt(int k) {
  int chk[26] = {}, count = 1;
//	cout << str[k] << endl;
  for(int i = 0; i < str[k].size(); i++) {
    int alpha = str[k][i] - 'a'; // 'a'를 빼줌으로써 참조 범위 오류를 피하는 것을 안함. 
    if(!chk[alpha]) chk[alpha] = count++;
    cnt[k][i] = chk[alpha];
//		cout << str[k][i] << ' ' << cnt[k][i] << ' ';
  }
//	cout << endl;
}

bool is_pair(int i, int j) {
  for(int k = 0; k < str[i].size(); k++) {
    if(cnt[i][k] != cnt[j][k]) return 0;
  }
  return 1;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> str[i];
    make_cnt(i);
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      ans += is_pair(i, j);
    }
  }
  cout << ans;
//	cin >> n;

  return 0;
}