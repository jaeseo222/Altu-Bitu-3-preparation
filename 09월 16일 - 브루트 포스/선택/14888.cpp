#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> number(11);
vector<int> opt(4);

int my_max = -(1e9 + 1);
int my_min = 1e9 + 1;

int calculation(int a, int b, int c) {
	switch (c) {
	case 0: //+
		return a + b;
	case 1: //-
		return a - b;
	case 2: //*
		return a * b;
	case 3: // 나누기 c++에서 음수 나누기가 어떻게 이루어 지는지 확인해주세요~!
		return a / b;
	}
}

void solution(int result, int idx) {
	if (idx == n) {

		my_max = max(my_max, result);
		my_min = min(my_min, result);

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (opt[i]) {
			opt[i]--;
			solution(calculation(result, number[idx], i), idx + 1);
			opt[i]++; 
		}
	}
}

/*
* Solution 한 번에 하나의 연산자를 선택하고 재귀 
*-> 함수의 매개변수로 그 시점에서 선택한 연산자로 계산한 결과(result)와 다음 연산에 사용할 숫자의 인덱스 정보 idx를 넘김
*  base는 다음 연산에 사용할 숫자의 인덱스가 n일 때 즉 숫자가 없을 때->result와 max, min 비교해서 값 갱신
*/

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> opt[i];
	}

	solution(number[0], 1);
	cout << my_max << '\n' << my_min;

	return 0;
}
