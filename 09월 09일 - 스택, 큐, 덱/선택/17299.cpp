#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int SIZE = 1e6 + 1;

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
vector<int> findNum(vector<int>& cnt, vector<int>& arr, int n) {
	stack<int> st; // 오등큰수 인덱스 저장
	vector<int> result(n, -1);

	for (int i = 0; i < n; i++) {
		// 오등큰수 찾을 때까지 갱신 & pop
		while (!st.empty() && cnt[arr[i]] > cnt[arr[st.top()]]) {
			result[st.top()] = arr[i];
			st.pop();
		}

		// 현재 참조하는 수가 오른쪽 원소들 중에서 오등큰수가 될 수 있으니 저장
		st.push(i);
	}

	return result;
}

/*
* 주의! 빈도수가 같으면 오등큰수x
*
* > 역방향 순회
* 역방향으로 검사하기 때문에 현재 검사하는 원소보다 오른쪽에 있는 수의 빈도수가 더 작거나 같다면,
* 오른쪽에 있는 수를 선택할 일은 없음. (가장 왼쪽에 있는 수를 선택하게 되므로 선택해도 현재 원소가 선택되기 때문)
*
* > 정방향 순회
* 역방향 순회의 반대와 마찬가지로, 현재 검사하는 원소보다 왼쪽에 있는 수의 빈도수가 더 작다면,
* 왼쪽에 있는 수를 선택할 일은 없음.
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