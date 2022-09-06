#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
/*
	cmath에서는 올림(ceil), 반올림(round), 내림(floor) 연산을 제공합니다
*/
using namespace std;

int main() {
	int N;
	double sum = 0.0;
	int mode; int max_cnt = 0;
	bool flag_first = false; bool flag_second = false;

	cin >> N;
	vector<int> v(N);
	vector<int> cnt(8001, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
		sum += v[i]; 
		int idx = v[i] + 4000; cnt[idx]++;
		if (max_cnt < cnt[idx]) {
			max_cnt = cnt[idx];
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 8001; i++) {
		if (max_cnt == cnt[i]) {
			if(!flag_first){
				mode = i;
				flag_first = true;
			}
			else if(!flag_second) {
				mode = i;
				flag_second = true;
			}
		}
	}
	
	//출력
	cout << (int)round(sum / N) << '\n'; 
	cout << v[floor(N / 2)] << '\n'; 
	cout << mode - 4000 << '\n';
	cout << v[N - 1] - v[0] << '\n';

	return 0;
}
