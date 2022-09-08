//2108번 - cnt 이용하여 최빈값 구하는 풀이
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
/*
	cmath에서는 올림(ceil), 반올림(round), 내림(floor) 연산을 제공합니다
*/
/*
* [힌트] 각 값을 구하기 위해 어떤 작업이 필요할까요? 앞에서 배운 내용을 복습해 봅시다~
* 입력값의 조건에 주목해주세요!
* -0을 나타내는 자료형은 없어요.
*
* 1. 산술 평균: 입력된 숫자들의 합을 숫자 개수로 나누기
* 2. 중앙값: 입력값 벡터 정렬 후 (n/2)번째 숫자 구하기. n이 홀수이므로 중앙값은 항상 (n/2)번째 인덱스
* 3. 최빈값: 각 숫자별로 빈도를 저장, 최대 빈도 구하기. 이후 findMode()함수 이용하여 최빈값 구하기
* 4. 범위: 입력받은 벡터 정렬 후 최댓값 - 최솟값
*/
using namespace std;

const int SCOPE = 4000; //입력되는 정수의 최대 절댓값

int findMode(int max_cnt, vector<int>& frequency) {
	//정렬된 벡터에서 최빈값을 찾아 반환하는 함수
	//최빈값이 여러 개라면 두번째로 작은 값을 반환
	int cnt = 0; int mode;
	for (int i = 0; i < 2 * SCOPE + 1; i++) {
		if (max_cnt == frequency[i]) { //최빈값 갱신
			mode = i;
			cnt++;
			if (cnt == 2) { //세번째 최빈값부터는 mode 값을 갱신하지 않음
				break;
			}
		}
	}
	return mode - SCOPE; //인덱스는 입력된 숫자 + 4000 이므로 4000을 빼준 값을 반환
}

int main() {
	int n;
	double sum = 0.0; //입력된 숫자의 합
	int max_freq = 0; //최빈값, 최빈값의 빈도수

	cin >> n;
	vector<int> v(n); //입력된 숫자를 저장할 벡터
	vector<int> frequency(2 * SCOPE + 1, 0); //각 숫자들(-4000~4000)의 빈도를 저장할 벡터

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
		frequency[v[i] + SCOPE]++; //빈도수 갱신. 인덱스 값이 음수가 안되게 유의
		if (max_freq < frequency[v[i] + SCOPE]) { 
			max_freq = frequency[v[i] + SCOPE]; //최대 빈도수 갱신
		}
	}
	sort(v.begin(), v.end());

	//출력
	cout << (int)round(sum / n) << '\n';		//산술평균: -0 안나오게 유의
	cout << v[n / 2] << '\n';			//중앙값
	cout << findMode(max_freq, frequency) << '\n';	//최빈값
	cout << v[n - 1] - v[0] << '\n';		//범위

	return 0;
}
