#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ci;//반복되는 형태는 typedef로 미리 선언하고 사용해요!
map<int, int> order;

//비교 정렬 함수 사용 시, 비교 변수는 함수 내에서 절대로 값이 변경되면 안돼 상수화를 권장해요!
//또 가독성을 위해, 같지 않을 경우에 대한 조건을 먼저 처리 하는 것을 권장해요! -> 국영수 문제를 참고해보세요!
bool cmp(const ci& a, const ci& b) {
	if (a.second != b.second) {
		return a.second > b.second; //빈도가 다르면 빈도수 내림차순
	}
	return order[a.first] < order[b.first]; //빈도가 같다면 순서 오름차순
	 
}


int main() {

	int n,c, num;
	map<int, int> frequency;

	cin >> n>> c;

	//정수값에 따라서 빈도수와 처음 나온 순서를 frequency와 order에 저장
	for (int i = 0; i < n; i++) {
		cin >> num;

		if (!frequency[num]) {//입력받은 정수의 frequency값이 0이면
			order[num] = i; //order에 처음 나온 순서 i기록
		}
		frequency[num]++;
	}

	/*
	* 정렬 순위
	* 1. 빈도수 내림차순
	* 2. 빈도수가 같다면 처음 나온 순서 오름차순
	*/
	vector<ci> v(frequency.begin(), frequency.end());//map은 정렬 함수가 따로 없어서 vector로 바꿔야해요!

	sort(v.begin(), v.end(), cmp); 

	for (int i = 0; i < v.size(); i++) {
		while (v[i].second--) {
			cout << v[i].first << ' ';
		}
	}

	return 0;
}
