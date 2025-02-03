#include <iostream>
#include <unordered_map>

// 13414번 수강신청

using namespace std;

int k, l; 
string str, arr[500000];
unordered_map<string, int> m;

int main() {
  cin >> k >> l;
  for(int i = 0; i < l; i++) {
    cin >> arr[i];
    if(m.find(arr[i]) != m.end()) arr[m[arr[i]]] = "";
    m[arr[i]] = i;
  }
  for(int i = 0; k && i < l; i++) { // i 범위 미지정으로 인한 출력초과 
//		cout << i << " " << arr[i] << endl;
    if(arr[i] != "") {
      cout << arr[i] << '\n'; // endl 시간초과 
      k--;
    }
  }
//	cin >> k;

  return 0;
} 