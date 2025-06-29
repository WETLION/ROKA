#include <iostream>
#include <stack>

// 2877번 4와 7 

using namespace std;

int n, chk = 1, sum = 0;
string ans;
stack<int> s;

int main() {
	cin >> n;
	do {
		s.push(chk);
		sum += chk *= 2;
	} while(n > sum);
	while(!s.empty()) {
		int now = s.top();
		s.pop();
		ans.push_back(n > sum - now ? '7' : '4');
		if(n <= sum - now) sum -= now; // if문을 반대로 짬 
	}
	cout << ans;

	return 0;
}