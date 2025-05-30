#include <iostream>
#include <algorithm>
#include <map>

// 25758번 유전자 조합 

using namespace std;

int n, ans[26], cnt;
string str;
map<string, int> m;

int main() {
	cin >> n;
	while(n--) {
		cin >> str;
		if(m.find(str) != m.end()) m[str]++;
		else m.insert({str, 1});
	}
	for(pair<string, int> st: m) {
		for(int i = 0; i < 2; i++) {
			for(pair<string, int> cmp: m) {
				if(cmp.first == st.first && st.second == 1) continue;
				ans[max(st.first[i], cmp.first[!i]) - 'A'] = 1;
			}
		}
	}
	for(int i = 0; i < 26; i++) cnt += ans[i];
	cout << cnt << endl;
	for(int i = 0; i < 26; i++) if(ans[i]) cout << char('A' + i) << " ";

	return 0;
}