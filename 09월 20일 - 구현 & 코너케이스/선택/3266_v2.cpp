#include<iostream>
#include<string>
using namespace std;

int calculateCharge(int h, int m, int time) {
	int ans = 0;
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
