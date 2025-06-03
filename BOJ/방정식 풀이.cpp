#include <iostream>
#include <vector>

// 6594번 방정식 풀이 

using namespace std;

string str;

int find_num(int *now) {
	int ret = 0;
	for(; *now < str.size() && '0' <= str[*now] && str[*now] <= '9';) ret = ret * 10 + str[(*now)++] - '0';
	--*now;
	return ret;
}

int paren(int *now) {
	int ret = 0, times = 0, chk = 1;
	vector<int> v;
	for(; str[*now] != ')'; (*now)++) {
		if(str[*now] == '(') {
			int temp = paren(&(++*now));
			if(times) v[v.size() - 1] *= temp;
			else v.push_back(temp);
		}
		else if(str[*now] == '+') {
			chk = 1;
			times = 0;
		}
		else if(str[*now] == '-') {
			chk = -1;
			times = 0;
		}
		else if(str[*now] == '*') times = 1;
		else if(!times) v.push_back(chk * find_num(now));
		else if(times) v[v.size() - 1] *= find_num(now);
//		cout << v.back() << endl;
	}
	for(int i: v) ret += i;
//	cout << ret << endl;
	return ret;
} 

int cal(int x) {
	int ret = 0, times = 0, chk = 1, x_chk = !x, rev = x ? 1 : -1;
	vector<int> v;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] == '(') {
			int temp = paren(&++i);
			if(times) v[v.size() - 1] *= temp * rev;
			else v.push_back(temp * chk * rev);
		}
		else if(str[i] == 'x') {
			x_chk = x;
			if(!times) v.push_back(1);
		}
		else if(str[i] == '=') {
			rev *= -1;
			chk = 1;
			times = 0;
			if(!x_chk) v.pop_back();
			x_chk = !x;
		}
		else if(str[i] == '+') {
			chk = 1;
			times = 0;
			if(!x_chk) v.pop_back();
			x_chk = !x;
		}
		else if(str[i] == '-') {
			chk = -1;
			times = 0;
			if(!x_chk) v.pop_back();
			x_chk = !x;
		}
		else if(str[i] == '*') times = 1;
		else if(!times) v.push_back(find_num(&i) * chk * rev);
		else if(times) v[v.size() - 1] *= find_num(&i);
//		cout << v.back() << " " << i << endl;
	}
//	cout << x_chk << endl;
	if(!x_chk) v.pop_back();
	for(int i: v) ret += i;
	return ret;
}

int main() {
	cout << fixed;
	cout.precision(6);
	for(int i = 1; ; i++) {
		cin >> str;
		if(cin.eof()) break;
		double x = cal(1), nx = cal(0);
//		cout << x << " " << nx << endl;
		cout << "Equation #" << i << endl;
		if(!x) {
			if(!nx) cout << "Infinitely many solutions.";
			else cout << "No solution.";
		}
		else cout << "x = " << nx / x;
		cout << endl << endl;
	}

	return 0;
}
