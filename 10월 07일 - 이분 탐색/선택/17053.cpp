#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ci; // 맥주의 선호도, 도수 레벨

const long long MAX_LEVEL = pow(2, 31);


bool cmp(ci beer1, ci beer2) {

	return beer1.second < beer2.second; // 도수레벨이 높은 순서대로
}

// 간레벨이 level일때 가능한 선호도의 최댓값
ll maxPrefSum(int n, vector<ci> beers, int level) {


	// 도수가 간 레벨 이하인 맥주들의 선호도 구하기
	vector<int> possibles;

	for (int i = 0; i < beers.size(); i++) {

		if (beers[i].second > level) {
			break;
		}
		possibles.push_back(beers[i].first);

	}

	if (possibles.size() < n) {
		return -1;
	}


	// 상위 n개의 선호도 합 계산 
	sort(possibles.begin(), possibles.end(), greater<ll>()); // 내림차순 정렬

	ll sum = 0; // 선호도 합
	for (int i = 0; i < n; i++) {
		sum += possibles[i];
	}

	return sum;

}
ll binarySearch(int n, int m, int k, vector<ci>& beers, ll left, ll right) {

	ll ans = -1;
	while (left <= right) {
		ll mid = (left + right) / 2; // 현재 기준 도수 레벨

		// 마실 수 있는 맥주가 n개조차 되지 않거나 선호도 합보다 작다면 
		if (maxPrefSum(n, beers, mid) < m) {
			left = mid + 1; //도수레벨을 높힘

		}
		else {// 선호도 합보다 크거나 같다면 
			right = mid - 1; // 도수레벨을 낮춤
			ans = mid;
		}

	}

	return ans;
}


/*
* [ 맥주 축제 ] - 이분 탐색
* 최소 도수 레벨을 1부터 1씩 증가시켜나가며 정답을 찾으면,
* 탐색 범위(1~2^31) 가 너무 넓기 때문에 시간 초과가 발생
* 따라서 이분 탐색으로 도수레벨을 변화시키면서 특정 조건을 만족하는 도수레벨의 최솟값을 구한다.
*
* 1. 현재 기준 도수레벨(mid)을 기준으로 마실 수 있는 맥주의 선호도의 최댓값을 구한다.
* 2-1. 마실 수 있는 맥주가 n개조차 되지 않거나 선호도 합이 모자라다면, 도수 레벨을 높여 마실 수 있는 맥주 개수를 늘린다.
* 2-2. 선호도 합이 충분하다면, 도수 레벨을 낮추어 마실 수 있는 맥주 개수를 줄인다.
* 이때, 조건(맥주 n개의 선호도 합 m 이상)을 만족시키는 경우의 수를 찾았더라도 바로 탐색을 종료하지 않는다.
* 왜냐하면 조건을 충족하는 레벨의 "최솟값" 을 구해야하기 때문이다.
*
* !주의! 선호도 합, 도수레벨 자체는 int 형 범위(-2^31 ~ 2^31) 이내이나 이분탐색과정에서 left+right값이
* int형 범위를 초과할 경우가 생기니 long long 자료형을 사용해야함에 유의
*
*/

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, k; // 축제 기간, 선호도 합, 맥주 종류 수

	cin >> n >> m >> k;

	vector<ci> beers(k);

	for (int i = 0; i < k; i++) {
		cin >> beers[i].first >> beers[i].second;

	}

	sort(beers.begin(), beers.end(), cmp); // 도수레벨 기준 오름차순 정렬
	cout << binarySearch(n, m, k, beers, 1, MAX_LEVEL);

}
