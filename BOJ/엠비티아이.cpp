#include <iostream>
#include <algorithm>

// 24725번 엠비티아이 

using namespace std;

int n, m;
string arr[200], cmp[4] = {"EI", "NS", "FT", "PJ"};

bool mbti_alpha_check(char alpha, int now) {
	for(int i = 0; i < 2; i++) {
		if(alpha == cmp[now][i]) return 1;
	}
	return 0;
}

bool mbti_linear_check(string str) {
	for(int i = 0; i < 4; i++) {
		if(!mbti_alpha_check(str[i], i)) return 0;
	}
	return 1;
}

bool mbti_reverse_check(string str) {
	for(int i = 0; i < 4; i++) {
		if(!mbti_alpha_check(str[3 - i], i)) return 0;
	}
	return 1;
}

int make_ans(int s_i, int f_i, int f_j, int p_k, int p_l) {
	int ret = 0;
	for(int i = s_i; i < f_i; i++) {
		for(int j = 0; j < f_j; j++) {
			string str;
			for(int k = 0, l = 0; k < 4 && l < 4; k = k + p_k, l = l + p_l) str.push_back(arr[i + k][j + l]);
			ret += mbti_linear_check(str) || mbti_reverse_check(str);
		}
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < m - 3; j++) {
//			string str; 
//			for(int k = 0; k < 4; k++) str.push_back(arr[i][j + k]);
//			ans += mbti_linear_check(str) || mbti_reverse_check(str);
//			cout << str << " ";
//			reverse(str.begin(), str.end());
//			cout << str << endl;
//		}
//	}
	cout << make_ans(0, n, m - 3, 0, 1) + 
//	for(int i = 0; i < n - 3; i++) {
//		for(int j = 0; j < m; j++) {
//			string str; 
//			for(int k = 0; k < 4; k++) str.push_back(arr[i + k][j]);
//			ans += mbti_linear_check(str) || mbti_reverse_check(str);
//			cout << str << " ";
//			reverse(str.begin(), str.end());
//			cout << str << endl;
//		}
//	}
	make_ans(0, n - 3, m, 1, 0) + 
//	for(int i = 0; i < n - 3; i++) {
//		for(int j = 0; j < m - 3; j++) {
//			string str; 
//			for(int k = 0; k < 4; k++) str.push_back(arr[i + k][j + k]);
//			ans += mbti_linear_check(str) || mbti_reverse_check(str);
//			cout << str << " ";
//			reverse(str.begin(), str.end());
//			cout << str << endl;
//		}
//	}
	make_ans(0, n - 3, m - 3, 1, 1) + 
//	for(int i = 3; i < n; i++) {
//		for(int j = 0; j < m - 3; j++) {
//			string str; 
//			for(int k = 0; k < 4; k++) str.push_back(arr[i - k][j + k]);
//			ans += mbti_linear_check(str) || mbti_reverse_check(str);
//			cout << str << " ";
//			reverse(str.begin(), str.end());
//			cout << str << endl;
//		}
//	}
	make_ans(3, n, m - 3, -1, 1);

	return 0;
}
