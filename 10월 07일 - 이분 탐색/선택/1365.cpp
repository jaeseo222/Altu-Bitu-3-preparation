#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void cut(int target, vector<int>& arr) {
	auto arr_left = lower_bound(arr.begin(), arr.end(), target);
	if (arr_left != arr.end()) {
		*arr_left = target;
	}
	else {
		arr.push_back(target);
	}
}

/*
* [꼬인 전깃줄]
*
* 전선이 꼬이지 않도록 전선을 최소한으로 잘라내야 함.
* => 꼬이는 이유는, 현재 연결된 전선의 왼쪽 전봇대보다 밑에 있는 전봇대에서, 현재 연결된 오른쪽 전봇대보다 위에 있는 전봇대와 연결되어 있기 때문
* => 전선을 최소한으로 잘라내고 남아있는 전선들을 보면 "가장 긴 증가하는 부분 수열 (LIS)"
*
* - 다이나믹 프로그래밍을 이용한 방법 : O(N^2)
* - 다이나믹 프로그래밍 + 이분탐색을 활용한 방법 : O(NlogN)
*
* 배열 = LIS를 저장
* 배열의 인덱스 = LIS 길이
* 배열의 원소값 = 해당 길이를 가지는 수열의 마지막 수 중, 가장 작은 값
*
* 1. 입력된 숫자가 정렬되어 있는 배열에 삽입될 수 있는 경우
*	-> 입력된 숫자값 이상이 처음 나타나는 위치의 값(lower bound)과 교체
*	-> 이상인 값을 찾았으니까, 입력된 숫자값이 더 작다는 의미 -> 수가 작아야 앞으로 LIS를 찾을 때 더 유리하기 때문
*
* 2. 배열이 비었거나, 입력된 숫자가 정렬되어 있는 배열의 마지막 원소보다 클 경우
*	-> 배열 뒤에 추가
*/

int main() {
	int n;
	vector<int> line;

	// 입력
	cin >> n;
	vector<int> twist(n);
	for (int i = 0; i < n; i++) {
		cin >> twist[i];
	}

	// 입력 & 계산
	for (int i = 0; i < n; i++) {
		cut(twist[i], line);
	}

	// 출력
	cout << n - line.size();
}