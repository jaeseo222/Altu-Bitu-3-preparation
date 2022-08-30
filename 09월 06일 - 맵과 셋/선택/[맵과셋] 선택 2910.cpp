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
		if (a.second > b.second) return 1;
		else return 0;
	}

	}

int main() {

	int N, C, i, num;
	map<int, int> frequency;
	
	

	cin >> N >> C;

	//입력받은 정수가 frequency에 있으면 값 +1 없으면 order 기록하고 freq+1
	for (i = 0; i < N; i++) {
		cin >> num;

		if (!frequency[num]) {
			order[num] = i;
			frequency[num] = 1;
		}
		else {
			frequency[num]++;
		}
	}

	//빈도가 많은 순서 -> 빈도가 같다면 order값이 작은....
	vector<pair<int, int>> v(frequency.begin(), frequency.end());
	sort(v.begin(), v.end(), cmp);

	for (i =0 ; i < v.size(); i++) {
		while (v[i].second) {
			cout << v[i].first << ' ';
			v[i].second--;
		}
	}

	return 0;
}
