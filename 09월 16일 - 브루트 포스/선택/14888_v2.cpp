#include<iostream>
using namespace std;

int n;
int number[11];
int opt[4];
//문제에서 주어진 연산 결과의 범위로 처음 MAX값과 MIN값 설정해주세요
int MAX = -1000000001;
int MIN = 1000000001;

void Solution(int result, int idx) {
	if (idx == n) {
		if (result > MAX) {
			MAX = result;
		}
		if (result < MIN) {
			MIN = result;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (opt[i]) {
			opt[i]--;
			if (i == 0) {
				Solution(result + number[idx], idx + 1);
			}
			else if (i == 1) {
				Solution(result - number[idx], idx + 1);

			}
			else if (i == 2) {
				Solution(result * number[idx], idx + 1);

			}
			else {
				Solution(result / number[idx], idx + 1);
			}
			opt[i]++; //재귀에서 return했을 때 상요한 연산자 다시 돌려놓기
		}
	}
	return;
}

/*
* Solution 한 번에 하나의 연산자를 선택하고 재귀 
*-> 함수의 매개변수로 그 시점에서 선택한 연산자로 계산한 결과(result)와 다음 연산에 사용할 숫자의 인덱스 정보 idx를 넘김
*  base는 다음 연산에 사용할 숫자의 인덱스가 n일 때 즉 숫자가 없을 때->result와 MAX, MIN 비교해서 값 갱신
*/

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}

	cin >> opt[0] >> opt[1] >> opt[2] >> opt[3];

	Solution(number[0], 1);
	cout << MAX << '\n' << MIN;

	return 0;
}