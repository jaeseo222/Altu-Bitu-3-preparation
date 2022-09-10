#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> number(11,0);
vector<int> opt(4, 0); //각 연산자 개수 저장
vector<int> opt_order; //연산자를 선택한 순서대로 저장하고(push_back) 재귀에서 return했을 때 뒤에서부터 원소를 뽑으니까(pop_back) vector를 써요!
int n;

//문제에서 주어진 연산 결과의 범위로 처음 MAX값과 MIN값 설정해주세요
int MAX = -1000000001;
int MIN = 1000000001;

int arithmeticOpt(int n1, int n2, int opt) {
	switch (opt)
	{
		case 0:
			return n1 + n2;
			break;
		case 1: 
			return n1 - n2;
			break;
		case 2 : 
			return n1 * n2;
			break;
		case 3:
			return n1 / n2; //C언어에서 음수 나누기가 어떻게 이루어지는지 공부해주세요!
			break;
		default:
			break;
	}
}

void  calc() {

	int result = number[0];
	for (int i = 1; i < n; i++) {
		result = arithmeticOpt(result, number[i], opt_order[i-1]);
	}

	if (result > MAX) {
		MAX = result;
	}
	if (result < MIN) {
		MIN = result;
	}
}

void Solution(int cnt) {

	if(cnt == n-1) {
		calc();
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (opt[i]) {

			opt[i]--;
			opt_order.push_back(i);

			Solution(cnt+1);

			opt[i]++;
			opt_order.pop_back();
		}
	}

}

/*
* Solution 한 번에 하나의 연산자를 선택하고 재귀
* base는 연산자의 개수가 n-1일 때 -> calc 함수로 현재 연산자 순서대로 계산해서 MAX, MIN갱신
* arithmeticOpt는 연산자의 종류에 따라서 계산해주는 함수
*/

int main(void) {

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}

	cin >> opt[0] >> opt[1] >> opt[2] >> opt[3];

	Solution(0);
	cout << MAX << '\n' << MIN;

	return 0;
}