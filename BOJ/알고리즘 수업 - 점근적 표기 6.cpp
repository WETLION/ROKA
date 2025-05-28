#include <iostream>
#include <cmath>

// 24370번 알고리즘 수업 - 점근적 표기 6 

using namespace std;

int a2, a1, a0, c1, c2, n0;

int main() {
	cin >> a2 >> a1 >> a0 >> c1 >> c2 >> n0;
	c1 = a2 - c1;
	c2 = a2 - c2;
	a1 *= -1;
//	cout << (double(a1) + sqrt(a1 * a1 - 4 * c1 * a0)) / double(2 * c1) << " " << (double(a1) - sqrt(a1 * a1 - 4 * c1 * a0)) / double(2 * c1) << " " << (double(a1) + sqrt(a1 * a1 - 4 * c2 * a0)) / double(2 * c2) << " " << (double(a1) - sqrt(a1 * a1 - 4 * c2 * a0)) / double(2 * c2) << endl;
	if(c1 < 0 || c2 > 0 || (a1 * a1 - 4 * c1 * a0 > 0 && ((double(a1) + sqrt(a1 * a1 - 4 * c1 * a0)) / double(2 * c1) > n0 || (double(a1) - sqrt(a1 * a1 - 4 * c1 * a0)) / double(2 * c1) > n0)) || (a1 * a1 - 4 * c2 * a0 > 0 && ((double(a1) + sqrt(a1 * a1 - 4 * c2 * a0)) / double(2 * c2) > n0 || (double(a1) - sqrt(a1 * a1 - 4 * c2 * a0)) / double(2 * c2) > n0))) cout << 0; // 근의 공식은 -b +- sqrt(b^2 -4ac) / 2a인데 -b를 그냥 b로 적어버림 
	else cout << 1;

	return 0;
}