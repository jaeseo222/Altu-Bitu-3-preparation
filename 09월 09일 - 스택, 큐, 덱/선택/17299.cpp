#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int SIZE = 1e6 + 1;

// 역방향 ver
vector<int> findNumEnd(vector<int>& cnt, vector<int>& arr, int n) {
	stack<int> st; // 오등큰수 저장
	vector<int> result(n, -1);

	for (int i = n - 1; i >= 0; i--) {
		// 오등큰수 찾을 때까지 pop
		while (!st.empty() && cnt[arr[i]] >= cnt[st.top()]) {
			st.pop();
		}

		// 오등큰수 찾은 경우
		if (!st.empty()) {
			result[i] = st.top();
		}

		// 현재 참조하는 수가 왼쪽 원소들 중에서 오등큰수가 될 수 있으니 저장
		st.push(arr[i]);
	}
	return result;
}

// 정방향 ver
vector<int> findNum(vector<int>& cnt, vector<int>& arr, int n) {
	stack<int> st; // 수의 인덱스 저장
	vector<int> result(n, -1);

	for (int i = 0; i < n; i++) {
		// 현재 원소를 오등큰수로 가질 때까지 저장 & pop
		while (!st.empty() && cnt[arr[i]] > cnt[arr[st.top()]]) {
			result[st.top()] = arr[i];
			st.pop();
		}

		// 현재 참조하는 수는 오등큰수가 아직 없는 수이기 때문에 저장
		st.push(i);
	}

	return result;
}
/*
* [오등큰수]
* 
* 주의! 빈도수가 같으면 오등큰수x
*
* > 역방향 순회
* 역방향으로 순회하며, 스택에 오등큰수가 될 가능성이 있는 수들을 저장
* 역방향으로 검사하기 때문에 현재 검사하는 원소가 스택에 들어있는 원소들보다 크다면, 스택에 들어있는 원소는 더 이상 오등큰수가 될 수 없음(가장 왼쪽에 있는 수를 선택하게 되므로 현재 원소가 선택되기 때문)
* 따라서 스택의 top()이 현재 원소보다 클 때까지 스택을 비우면서 오등큰수를 효율적으로 찾을 수 있음
* 
* > 정방향 순회
* 정방향으로 순회하며, 스택에 오등큰수가 아직 없는 수들을 저장
* 스택에 들어있는 원소들 중, 현재 검사하는 원소가 오등큰수가 되는 원소들은 모두 꺼내서 현재 검사 원소를 오등큰수로 저장
* 따라서 오등큰수를 찾은 수는 없애고, 오등큰수를 아직 찾지 못한 수는 스택에 계속 쌓으면서 오등큰수를 효율적으로 찾을 수 있음
*/
int main() {
	int n;
	vector<int> cnt(SIZE, 0), result; // 각 원소의 개수, 결과 저장

	// 입력
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	// 계산
	// 역방향 순회
	result = findNumEnd(cnt, arr, n);
	// 정방향 순회
	// result = findNum(cnt, arr, n);


	// 출력
	for (int i = 0; i < n; i++) {
		cout << result[i] << ' ';
	}
}