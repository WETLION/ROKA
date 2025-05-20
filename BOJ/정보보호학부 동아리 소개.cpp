#include <iostream>

// 28691번 정보보호학부 동아리 소개 

using namespace std;

char c;

int main() {
	cin >> c;
	if(c == 'M') cout << "MatKor";
	else if(c == 'W') cout << "WiCys";
	else if(c == 'C') cout << "CyKor";
	else if(c == 'A') cout << "AlKor";
	else cout << "$clear";

	return 0;
} 