#include <iostream>
#include <cmath>

// 1344번 축구 

using namespace std;

double a, b, ans, sum;
long long combi[20], prime[10] = {2, 3, 5, 7, 11, 13, 17}, facto[20] = {1, 1};

// 어차피 가능한 소수는 2, 3, 5, 7, 11, 13, 17이다. 

int main() {
	cout << fixed;
	cout.precision(16);
	for(long long i = 2; i < 20; i++) facto[i] = facto[i - 1] * i;
	for(int i = 0; i < 7; i++) combi[i] = facto[18] / facto[prime[i]] / facto[18 - prime[i]];
	cin >> a >> b;
	a /= 100;
	b /= 100;
	for(int i = 0; i < 7; i++) {
		ans += (pow(a, prime[i]) * pow(1.0 - a, 18 - prime[i]) + pow(b, prime[i]) * pow(1.0 - b, 18 - prime[i])) * combi[i];
		sum += pow(b, prime[i]) * pow(1.0 - b, 18 - prime[i]) * combi[i];
	}
	for(int i = 0; i < 7; i++) {
		ans -= pow(a, prime[i]) * pow(1.0 - a, 18 - prime[i]) * sum * combi[i];
	}
	cout << ans;

	return 0;
}