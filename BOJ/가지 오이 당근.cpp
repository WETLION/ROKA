#include <iostream>
#include <cstdio>

// 31632번 가지 오이 당근

using namespace std;

int t, n;
char v[100001], vv[100001]; // string을 모두 char 배열로 교체 후 scanf로 전체 변환하니 시간 초과 해결 

int is_draw(char str[]) {
	int chk = 0;
	if(str[0] == 'D') chk = 1;
	for(int i = 0; i < n; i++) {
		if(chk && str[i] != 'D' || !chk && str[i] == 'D') return -1;
	}
	return chk;
}

bool is_diff_wl(char str[]) {
	char chk = str[0];
	for(int i = 0; i < n; i++) {
		if(chk != str[i]) return 0;
	}
	return 1;
}

int is_wl(char str[], char cmp[]) {
	if(is_diff_wl(cmp)) return 0;
	int g = 0, o = 0, d = 0, chk = 0, all = 1;
	for(int i = 0; i < n; i++) {
		if(str[i] != '?') all = 0;
		if(str[i] == 'G') {
			if(!g) g = cmp[i] == 'W' ? 1 : -1;
			else if(cmp[i] == 'W' && g == -1 || cmp[i] == 'L' && g == 1) return 0;
		}
		else if(str[i] == 'O') {
			if(!o) o = cmp[i] == 'W' ? 1 : -1;
			else if(cmp[i] == 'W' && o == -1 || cmp[i] == 'L' && o == 1) return 0;
		}
		else if(str[i] == 'D') {
			if(!d) d = cmp[i] == 'W' ? 1 : -1;
			else if(cmp[i] == 'W' && d == -1 || cmp[i] == 'L' && d == 1) return 0;
		}
	}
	if(g == 1 && o == 1 || g == 1 && d == 1 || o == 1 && d == 1 || g == -1 && o == -1 || g == -1 && d == -1 || o == -1 && d == -1) return 0; // W가 두 문자인 경우 혹은 L이 두 문자인 경우를 걸러야 함. 
	if(g == 1 && d != -1 || o == -1 && d != 1) return 1;
	if(o == 1 && g != -1 || d == -1 && g != 1) return 2;
	if(d == 1 && o != -1 || g == -1 && o != 1 || all) return 3;
	return 0;
}

int main() {
	cin >> t;
	while(t--) {
		scanf("%d %s %s", &n, &v, &vv);
		int chk = is_draw(vv), g = 0, o = 0, d = 0;
		for(int i = 0; i < n; i++) {
			if(v[i] == 'G') g++;
			else if(v[i] == 'O') o++;
			else if(v[i] == 'D') d++;
		}
		if(chk == 1) {
			if(g && o && d) { // 셋 다 있으면서 물음표가 있는 경우를 고려해야함 
				printf("YES\n");
				for(int i = 0; i < n; i++) {
					if(v[i] == '?') printf("G");
					else printf("%c", v[i]);
				}
				printf("\n");
			}
			else if(g && o) {
				printf("YES\n");
				for(int i = 0; i < n; i++) {
					if(v[i] == '?') printf("D");
					else printf("%c", v[i]);
				}
				printf("\n");
			}
			else if(g && d) {
				printf("YES\n");
				for(int i = 0; i < n; i++) {
					if(v[i] == '?') printf("O");
					else printf("%c", v[i]);
				}
				printf("\n");
			}
			else if(o && d) {
				printf("YES\n");
				for(int i = 0; i < n; i++) {
					if(v[i] == '?') printf("G");
					else printf("%c", v[i]);
				}
				printf("\n");
			}
			else if(g && !o && !d) { // 한 가지 종류만 나옴으로 인해서 비기는 경우를 계산하지 않음
				printf("YES\n");
				for(int i = 0; i < n; i++) {
					if(v[i] == '?') printf("G");
					else printf("%c", v[i]);
				}
				printf("\n");
			}
			else if(o && !g && !d) { // 한 가지 종류만 나옴으로 인해서 비기는 경우를 계산하지 않음
				printf("YES\n");
				for(int i = 0; i < n; i++) {
					if(v[i] == '?') printf("O");
					else printf("%c", v[i]);
				}
				printf("\n");
			}
			else if(d && !g && !o) { // 한 가지 종류만 나옴으로 인해서 비기는 경우를 계산하지 않음
				printf("YES\n");
				for(int i = 0; i < n; i++) {
					if(v[i] == '?') printf("D");
					else printf("%c", v[i]);
				}
				printf("\n");
			}
			else if(!g && !o && !d) { // 비기면서 모두 물음표인 경우를 고려 안함
				printf("YES\n");
				for(int i = 0; i < n; i++) {
					printf("G");
				}
				printf("\n");
			}
			else {
				printf("NO\n");
				continue;
			}
		}
		else if(!chk) {
			if(g && o && d) {
				printf("NO\n");
				continue;
			}
			else {
				chk = is_wl(v, vv);
				if(chk) {
					printf("YES\n");
					if(g && o) {
						for(int i = 0; i < n; i++) {
							if(v[i] == '?') {
								if(vv[i] == 'W') printf("G");
								else printf("O");
							}
							else printf("%c", v[i]);
						}
						printf("\n");
					}
					else if(g && d) {
						for(int i = 0; i < n; i++) {
							if(v[i] == '?') {
								if(vv[i] == 'W') printf("D");
								else printf("G");
							}
							else printf("%c", v[i]);
						}
						printf("\n");
					}
					else if(o && d) {
						for(int i = 0; i < n; i++) {
							if(v[i] == '?') {
								if(vv[i] == 'W') printf("O");
								else printf("D");
							}
							else printf("%c", v[i]);
						}
						printf("\n");
					}
					else if(g) {
						for(int i = 0; i < n; i++) {
							if(v[i] == '?') {
								if(vv[i] == 'W') {
									if(chk == 1) printf("G");
									else printf("D"); // ?가 이겨야하면서 원 문자가 져야하는 경우를 반대로 계산함. 
								}
								else {
									if(chk == 1) printf("O");
									else printf("G");
								}
							}
							else printf("%c", v[i]);
						}
						printf("\n");
					}
					else if(o) {
						for(int i = 0; i < n; i++) {
							if(v[i] == '?') {
								if(vv[i] == 'W') {
									if(chk == 2) printf("O");
									else printf("G"); // ?가 이겨야하면서 원 문자가 져야하는 경우를 반대로 계산함. 
								}
								else {
									if(chk == 2) printf("D");
									else printf("O");
								}
							}
							else printf("%c", v[i]);
						}
						printf("\n");
					}
					else {
						for(int i = 0; i < n; i++) {
							if(v[i] == '?') {
								if(vv[i] == 'W') {
									if(chk == 3) printf("D");
									else printf("O"); // ?가 이겨야하면서 원 문자가 져야하는 경우를 반대로 계산함. 
								}
								else {
									if(chk == 3) printf("G");
									else printf("D");
								}
							}
							else printf("%c", v[i]);
						}
						printf("\n");
					}
				}
				else {
					printf("NO\n");
					continue;
				}
			}
		}
		else {
			printf("NO\n");
			continue;
		}
	}
//	cin >> n;

	return 0;
}