#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

map<int, int> order;
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {//빈도가 같다면
		if (order[a.first] < order[b.first])  return 1;//a가 더 빨리 나왔으면
		else return 0;
	}
	else {//빈도가 다르다면
		if (a.second > b.second) return 1; //a의 빈도가 더 크면 
		else return 0;
	}

	}

int main() {

	int N, C, i, num;
	map<int, int> frequency;

	cin >> N >> C;
	//정수값에 따라서 빈도수와 처음 나온 순서를 frequency와 order에 저장
	for (i = 0; i < N; i++) {
		cin >> num;

		if (!frequency[num]) {//입력받은 정수의 frequency값이 0이면
			order[num] = i; //order에 처음 나온 순서 i기록
			frequency[num] = 1; // 빈도수 1로 설정
		}
		else { // 입력받은 정수의 frequency값이 0이 아니면 즉 이미 한 번 나왔으면
			frequency[num]++;//빈도수 증가
		}
	}

	/*
	* 정렬 순쉬
	* 1. 빈도수 내림차순
	* 2. 빈도수가 같다면  order 오름차순
	*/
	vector<pair<int, int>> v(frequency.begin(), frequency.end());

	//빈도순으로 정렬하되 빈도가 같은 경우를 정렬하기 위해 cmp비교 함수 사용
	sort(v.begin(), v.end(), cmp);

	for (i =0 ; i < v.size(); i++) {
		while (v[i].second) {
			cout << v[i].first << ' ';
			v[i].second--;
		}
	}

	return 0;
}