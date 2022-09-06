#include<iostream>
using namespace std;

// 유클리드 호제법
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
/*
* [링]
* 몇 바퀴 도는지 기약 분수 형태 A/B로 출력
* -> 기약 분수를 구하기 위해, 두 수의 최대공약수를 구하여 나누어줌.
*/
int main() {
	int n, a, b;

	// 입력
	cin >> n >> a;
	while (n--) {
		if (n < 1) break;
		cin >> b;

		// 연산 + 출력
		int g = gcd(a, b);
		cout << a / g << "/" << b / g << "\n";
	}
}