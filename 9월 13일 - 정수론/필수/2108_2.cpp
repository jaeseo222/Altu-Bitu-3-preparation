#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
/*
	cmath에서는 올림(ceil), 반올림(round), 내림(floor) 연산 등을 제공합니다
*/
/*
* 힌트: 각 값을 구하기 위해 어떤 작업이 필요할까요? 앞에서 배운 내용을 복습해 봅시다~
* 입력값의 범위에 주목해주세요!
* -0을 나타내는 자료형은 없어요.
*/
#define SCOPE 4000
using namespace std;

// 비교함수
bool cmp(const pair<int,int> & a, const pair<int, int> & b) {
   //개수(second)에 대해 내림차순, 값(first)에 대해 오름차순으로 정렬
	if (a.second != b.second) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int findMode(int n, vector<pair<int,int>>& frequency) {
    //정렬된 벡터에서 최빈값을 찾아 반환하는 함수
    //최빈값이 여러 개라면 두번째로 작은 값을 반환
    
    //개수에 대해 내림차순, 값에 대해 오름차순으로 정렬
    sort(frequency.begin(), frequency.end(), cmp);

    //최빈값이 여러개인지 확인
    if (frequency[0].second == frequency[1].second) {
        return frequency[1].first;
    }
    return frequency[0].first;
}

int main() {
	int n;
	double sum = 0.0; //입력된 숫자의 합
	bool flag_first = false; bool flag_second = false;

	cin >> n;
	vector<int> v(n);
	vector<pair<int, int>> frequency(2 * SCOPE + 1); // 정수의 값와 해당 정수 개수를 pair로 묶어서 저장
	//기본적으로 0으로 초기화된다
	//각 pair는 first, second로 접근 가능

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
		frequency[v[i] + SCOPE].first = v[i]; //first: 값
		frequency[v[i] + SCOPE].second++; //second: 개수
	}
	sort(v.begin(), v.end());


	//출력
	cout << (int)round(sum / n) << '\n'; //산술평균: -0 안나오게 유의
	cout << v[n / 2] << '\n'; //중앙값
	cout << findMode(n, frequency) << '\n';	//최빈값
	cout << v[n - 1] - v[0] << '\n'; //범위

	return 0;
}
