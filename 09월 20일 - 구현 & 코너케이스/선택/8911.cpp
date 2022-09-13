#include<iostream>
using namespace std;

int turtle(string str) {
	// 북 동 남 서
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };

	// 각 최대 최소 x, y 위치값
	int  my = 0, sy = 0, mx = 0, sx = 0;

	// 맨 처음은 북쪽 방향
	int dire = 0;

	// 현재 위치 (0, 0)
	pair<int, int> curr = { 0, 0 };

	for (int i = 0; i < str.length(); i++) {
		switch (str[i])
		{
		case 'F':
			curr = make_pair(curr.first + dx[dire], curr.second + dy[dire]);
			break;
		case 'B':
			curr = make_pair(curr.first - dx[dire], curr.second - dy[dire]);
			break;
		case 'L':
			dire = (dire + 1) % 4;
			break;
		case 'R':
			dire = (dire + 3) % 4;
			break;
		}
		my = max(my, curr.second);
		sy = min(sy, curr.second);
		mx = max(mx, curr.first);
		sx = min(sx, curr.first);
	}
	return (my - sy) * (mx - sx);
}
int main() {
	int t;
	string str;

	// 입력
	cin >> t;
	while (t--) {
		cin >> str;
		// 계산 & 출력
		cout << turtle(str) << '\n';
	}
}