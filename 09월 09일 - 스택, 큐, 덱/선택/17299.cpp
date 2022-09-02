#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int SIZE = 1e6 + 1;
int num[SIZE]; // 각 원소의 개수

vector<int> findNum(vector<int>& arr, int n) {
	stack<int> big_num; // 오등큰수 저장
	vector<int> result(n);

	for (int i = n - 1; i >= 0; i--) {
		// 맨 오른쪽부터 참조하여 오등큰수 찾을 때까지 pop
		while (!big_num.empty() && num[arr[i]] >= num[big_num.top()]) {
			big_num.pop();
		}

		// 오등큰수 못 찾은 경우
		if (big_num.empty()) {
			result[i] = -1;
		}
		// 찾은 경우
		else {
			result[i] = big_num.top();
		}

		// 현재 참조하는 수가 왼쪽 원소들 중에서 오등큰수가 될 수 있으니 저장
		big_num.push(arr[i]);
	}

	return result;
}
int main() {
	int n;
	vector<int> input_set, result;

	// 입력
	cin >> n;
	input_set.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> input_set[i];
		num[input_set[i]]++;
	}

	// 계산
	result = findNum(input_set, n);

	// 출력
	for (int i = 0; i < n; i++)
		cout << result[i] << ' ';
}