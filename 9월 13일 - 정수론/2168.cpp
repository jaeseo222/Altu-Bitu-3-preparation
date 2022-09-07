#include<iostream>

using namespace std;

//최대공약수를 구하는 함수(유클리드 호제법)
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << n + m - gcd(n, m);
}