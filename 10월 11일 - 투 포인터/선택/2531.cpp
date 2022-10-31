#include<iostream>
#include<vector>

using namespace std;


int calMax(vector<int> &food, int k, int n, int d ,int c) {
	int left = 0, right = k - 1;
	int result = 0, count = 0;
	vector<int> check(d + 1, 0);

	//초기화
	//쿠폰으로 먹을 수 있는 초밥
	check[c]++;
	count++;
	
	//연속해서 먹을 수 있는 초밥
	for (int i = 0; i < k; i++) {
		check[food[i]]++;
		if (check[food[i]] == 1) {
			count++;
		}
	}

	

	//슬라이딩 윈도우
	while (left < n) {
		//left 접시 선택 제거
		check[food[left]]--;
		if (check[food[left++]] == 0) {
			count--;
		}
		//right+1 접시 새로 선택
		right = (right + 1) % n;
		check[food[right]]++;
		if (check[food[right]] == 1) {
			count++;
		}
		result = max(result, count);
	}
	return result;
}
int main() {
	int n, d, k, c;
	
	cin >> n >> d >> k >> c;
	vector<int> food(n + 1, 0);

	for (int i = 0; i < n; i++) {
		cin >> food[i];
	}

	cout << calMax(food, k, n,d,c);

	return 0;
}
