#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <deque>

// 16115번 팬이에요 

using namespace std;

struct node {
	long long xx, yy;
};

int n;
long long x, y, r_m;
double ans;
deque<node> dq;

int main() {
	cout << fixed;
	cout.precision(6); // 소수점 6자리 출력 안해서 틀림;; 
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		if(r_m < x * x + y * y) {
			r_m = x * x + y * y;
			dq.clear();
			dq.push_back({x, y});
		}
		else if(r_m == x * x + y * y) dq.push_back({x, y});
	}
	if(dq.size() == 1) {
		cout << 360;
		return 0;
	}
	for(int i = 1; i < dq.size(); i++) {
		if(atan2(dq[i - 1].xx, dq[i - 1].yy) < atan2(dq[i].xx, dq[i].yy)) {
//			cout << i << endl;
			for(int j = i; j < dq.size(); j++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			break;
		}
	}
//	for(int i = 0; i < dq.size(); i++) cout << dq[i].xx << " " << dq[i].yy << endl;
	for(int i = 1; i < dq.size(); i++) {
		double angle = fabs(atan2(dq[i - 1].xx, dq[i - 1].yy) - atan2(dq[i].xx, dq[i].yy)) * 180 / M_PI;
//		cout << angle << endl;
		ans = max(ans, angle);
	}
//	cout << fabs(atan2(dq.back().xx, dq.back().yy) - atan2(dq[0].xx, dq[0].yy)) * 180 / M_PI << endl;
	cout << max(ans, 360 - fabs(atan2(dq.back().xx, dq.back().yy) - atan2(dq[0].xx, dq[0].yy)) * 180 / M_PI); // dq[n - 1]이 아니고 dq.back()임 
	cin >> n;

	return 0;
}
