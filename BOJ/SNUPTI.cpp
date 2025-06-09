#include <iostream>
#include <vector>
#include <set>

// 25624번 SNUPTI

using namespace std;

int n, m, arr[30], t = 1;
string str;
vector<int> v(30, -1);
set<string> s;

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> str;
//		cout << str << endl;
		if(s.find(str) != s.end()) {
			cout << "NO";
			cin >> n;
			return 0;
		}
		s.insert(str);
		for(int j = 0; j < n; j++) {
			int now = str[j] - 'A';
			if(v[now] != j && v[now] >= 0) {
				cout << "NO";
				return 0;
			}
			else if(v[now] < 0) {
				v[now] = j;
				arr[j]++;
			}
		}
	}
	for(int i = 0; i < n; i++) t *= arr[i];
	if(t == m) {
		cout << "YES" << endl;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 26; j++) {
				if(v[j] == i) cout << char('A' + j);
			}
			cout << endl;
		}
	}

	else cout << "NO";
	cin >> n;

	return 0;
} 