#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> vi;

void men(int num, vi &sw) {
	int idx = num-1;
	while (idx < sw.size()) { //자신이 받은 숫자의 배수 인덱스 스위치 상태 변경
		sw[idx] = 1 - sw[idx];
		idx += num;
	}
}

void women(int num, vi& sw) {
	//자신의 스위치 기준, 좌우가 대칭이면서 가장 많은 스위치를 포함하는 구간의 스위치 상태 변경
	int i = 0;
	while (num - i >= 0 && num + i < sw.size()) {
		if (sw[num - i] == sw[num + i]) {
			sw[num - i] = sw[num + i] = 1 - sw[num + i];
		}
		else {
			break;
		}
		i++;
	}
}

void printRes(vi &sw) {
	//결과 출력
	for (int i = 0; i < sw.size(); i++) {
		cout << sw[i] << ' ';
		if (i % 20 == 19) {
			cout << '\n';
		}
	}
}


int main() {
	int students, n;
	cin >> n;
	vi sw(n); //스위치 상태 저장할 벡터
	for (int i = 0; i < n; i++) {
		cin >> sw[i]; //초기 스위치 상태
	}
	cin >> students; //학생 수
	while (students--) {
		//성별과 스위치 번호
		int gender, num;
		cin >> gender >> num;
		if (gender == 1) { //남학생
			men(num, sw);
		}
		else { //여학생
			women(num - 1, sw);
		}
	}
	printRes(sw);

}
