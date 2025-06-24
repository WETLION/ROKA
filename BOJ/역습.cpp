#include <iostream>
#include <vector>
#include <algorithm> 

// 3976번 역습 

using namespace std;

int c, n, l[2], s[2], input;

int main() {
	cin >> c;
	while(c--) {
		cin >> n >> l[0] >> l[1] >> s[0] >> s[1];
		vector<int> p[2], d[2], dp[2] = {{l[0]}, {l[1]}};
		for(int i = 1; i < n; i++) {
			cin >> input;
			p[0].push_back(input);
		}
		for(int i = 1; i < n; i++) {
			cin >> input;
			d[0].push_back(input); // 패스 / 드리블 순서 오류 
		}
		for(int i = 1; i < n; i++) {
			cin >> input;
			p[1].push_back(input);
		}
		for(int i = 1; i < n; i++) {
			cin >> input;
			d[1].push_back(input);
		}
		for(int i = 0; i < n - 1; i++) {
			int ins[2] = {min(dp[0].back() + d[0][i], dp[1].back() + p[1][i]), min(dp[1].back() + d[1][i], dp[0].back() + p[0][i])}; // 사전에 각각의 값을 계산해놓지 않으면, dp[0].back()의 값이 변경됨. 
			dp[0].push_back(ins[0]);
			dp[1].push_back(ins[1]);
		}
//		cout << dp[0].back() << " " << dp[1].back() << endl;
		cout << min(dp[0].back() + s[0], dp[1].back() + s[1]) << endl;
	}	

	return 0;
}
