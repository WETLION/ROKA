#include <iostream>
#include <string>
#include <deque>

// 14713번 앵무새

using namespace std;

int n;
string str;
deque<string> dq[100];

int main() {
	cin >> n;
	getchar();
	for(int i = 0; i < n; i++) {
		getline(cin, str);
		string tmp;
		for(char j: str) {
			if(j == ' ') {
				dq[i].push_back(tmp);
				tmp.clear();
				continue;
			}
			tmp += j;
		}
		dq[i].push_back(tmp);
	}
	while(1) {
		cin >> str;
		if(cin.eof()) break;
		for(int i = 0; i <= n; i++) {
			if(i == n) {
				cout << "Impossible";
				return 0;
			}
			if(dq[i].front() == str) {
				dq[i].pop_front();
				break;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(dq[i].size()) { // 만약 앵무새의 단어가 남아도 문장은 완성될 수 없음. 
			cout << "Impossible";
			return 0;
		}
	}
	cout << "Possible";

	return 0;
}