#include <iostream>
#include <vector>
using namespace std;

//1. LED의 각 자리를 비트로 표현
//2. x와 n또한 각 자리를 비트로 표현하고 xor연산을 통해 서로 다른 비트의 개수를 구해주기
//3. 다른 비트의 개수가 1이상 p이하면 조건에 만족한다!

int const NUMBER = 10;//0~9
int const LED_NUMBER = 7;
vector <int> number_bit = {0b1111110, 0b0110000, 0b1101101,0b1111001,0b0110011,0b1011011, 0b1011111, 0b1110000,0b1111111, 0b1111011};

int calcDiff(vector<int> & start_number, int n, int k) {//x와 n의 다른 bit 개수를 세주는 함수
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		unsigned char diff = (start_number[i] ^ number_bit[n % 10]);//xor연산을 해주면 비트가 다른 부분만 1이 남는다
		for (int j = 0; j < LED_NUMBER; j++) {//diff의 비트를 왼쪽으로 하나씩 옮겨가면서 1과 and연산을 한 결과를 cnt에 더해준다.
			cnt += (diff & 1);
			diff >>= 1;
		}
		n /= NUMBER;
	}
	return cnt;
}
int solution(int n, int k, int p, int x) {
	//x 처음 LED에 켜져있는 숫자의 bit를 저장
	vector<int> start_number(k);
	int tmp_x = x;
	for (int i = 0; i < k; i++) {
		start_number[i] = number_bit[tmp_x % NUMBER];
		tmp_x /= NUMBER;
	}
	
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x) {
			continue;
		}
		int diff = calcDiff(start_number, i, k);
		if (diff > 0 && diff <= p) {//다른 비트의 개수가 1이상 p이하이면 카운트
			result++;
		}
	}

	return result;
}

int main() {
	int n, k, p, x;
	
	cin >> n >> k >> p >> x;
	cout << solution(n,k,p,x);
	return 0;
}

