#include<iostream>
#include<string>
using namespace std;
/*
통화 시간이 최대 60까지이므로 입력받은 통화 시간만큼 분당 요금을 더해주는 반복문으로 풀이
->7시~18시 : +10원
->그 외: +5원
*/
int calculateCharge(int h, int m, int time) {
	int ans = 0;
	//통화 시각이 0이 될 때까지 반복
	while (time--) {
		if (h >= 7 && h < 19) {
			ans += 10;
		}
		else {
			ans += 5;
		}
		h += (++m / 60) % 24;
		m %= 60;
	}
	return ans;
}

int main() {
	int n, m, time;
	int charge = 0;
	string h;

	cin >> n;

	while(n--){
		getline(cin, h, ':');
		cin >> m >> time;
		charge+ = calculateCharge(stoi(h),m,time);
	}

	cout << charge;
}
