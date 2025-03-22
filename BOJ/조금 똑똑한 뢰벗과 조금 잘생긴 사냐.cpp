#include <iostream>
#include <deque>

// 14856번 조금 똑똑한 뢰벗과 조금 잘생긴 사냐

using namespace std;

long long n;
deque<long long> dq = {1, 1}, ans;

int main() {
	cin >> n;
//	cout <<  *(v.end() - 2) << " " << *(v.end() - 1);
	while(dq.front() + *(dq.begin() + 1) <= n) dq.push_front(dq.front() + *(dq.begin() + 1));
//	for(long long i: v) cout << i << endl;
	dq.pop_back();
	for(long long i: dq) {
		if(i > n) continue;
		n -= i;
		ans.push_front(i);
	}
	if(n) cout << -1;
	else {
		cout << ans.size() << endl;
		for(long long i: ans) cout << i << " ";
	}
	cin >> n;

	return 0;
} 