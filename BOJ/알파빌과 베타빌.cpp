#include <iostream>
#include <vector>

// 29615번 알파빌과 베타빌

using namespace std;

int n, m, input, cnt;
vector<int> v;

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> input;
    v.push_back(input);
  }
  for(int i = 0; i < m; i++) {
    cin >> input;
    for(int j = 0; j < m; j++) {
      if(v[j] == input) { // v[j]를 v[i]로 둠
        cnt--;
        break;
      }
    }
    cnt++;
  }
  cout << cnt;

  return 0;
}