#include<iostream>
#include<algorithm>

using namespace std;
int calMax(int count, int* check, int* food,int k,int n) {
	int left = 0,right = k - 1;
	int result = 0;

	while (left < n) {
		result = max(result, count);
		//left의 접시 선택 제거
		check[food[left]]--;
		if (check[food[left++]] == 0) {
			count--;
		}
		//right+1의 접시 새로 선택
		right = (right + 1) % n;
		check[food[right]]++;
		if (check[food[right]] == 1) {
			count++;
		}
	}
	return result;
}
int main() {
	int n, d, k, c;
	int food[30001] = {};
	int check[3001] = {};
	int count = 0;
	cin >> n >> d >> k >> c;

	//투 포인터
	int left = 0, right = k - 1;

	for (int i = 0; i < n; i++) {
		cin >> food[i];
	}
	//연속해서 먹을 수 있는 초밥
	for (int i = 0; i < k; i++) {
		check[food[i]]++;
		if (check[food[i]] == 1) {
			count++;
		}
	}
	//쿠폰으로 먹을 수 있는 초밥
	check[c]++;
	if (check[c] == 1) {
		count++;
	}
	cout<<calMax(count, check, food, k, n);
	
	return 0;
}
