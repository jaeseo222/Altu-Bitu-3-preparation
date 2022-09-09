#include <iostream>

using namespace std;
/*
  * 가능한 최소 소인수는 2, 최대 인수는 N
  * 브루트포스로 소인수 찾기. 중복에 주의!
 */
int main()
{
	int n;
	// 입력
	cin >> n;

	// 연산 & 출력
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			n /= i; // 나누기
			cout << i << '\n';
			i--; // 중복 확인
			if (n == 1) { // 나눈 결과가 1이면 종료
				break;
			}
		}
	}

	return 0;
}
