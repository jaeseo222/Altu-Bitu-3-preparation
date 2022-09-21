#include<iostream>
using namespace std;

int getMinimumArea(string str) {
	// 북 동 남 서
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	// 각 최대 최소 x, y 위치값
	int  max_y = 0, min_y = 0, max_x = 0, min_x = 0;

	// 맨 처음은 북쪽 방향
	int direction = 0;

	// 현재 위치 (0, 0)
	pair<int, int> curr = { 0, 0 };

	for (int i = 0; i < str.length(); i++) {
		switch (str[i])
		{
		case 'F':
			curr = { curr.first + dx[direction], curr.second + dy[direction] };
			break;
		case 'B':
			curr = { curr.first - dx[direction], curr.second - dy[direction] };
			break;
		case 'L':
			direction = (direction + 1) % 4;
			break;
		case 'R':
			direction = (direction + 3) % 4;
			break;
		}
		max_y = max(max_y, curr.second);
		min_y = min(min_y, curr.second);
		max_x = max(max_x, curr.first);
		min_x = min(min_x, curr.first);
	}
	return (max_y - min_y) * (max_x - min_x);
}
/*
* [거북이]
*
* 문제에 나와있는 대로 구현
*
* 2차원 평면 위에서 움직이는 거북이 로봇
* -> 현재 위치를 { x, y } 로 구현 -> pair
*
* 거북이에게 내릴 수 있는 명령
* - F : 한 눈금 앞으로
* - B : 한 눈금 뒤로
* - L : 왼쪽으로 90도 회전
* - R : 오른쪽으로 90도 회전
*
* 거북이에게 내린 명령대로 회전 및 이동 진행
* -> 방향 배열의 인덱스를 활용해 회전 구현. 
*	 인덱스 + 1 되었을 때, 오른쪽으로 회전을 구현하기 위해 방향 배열의 순서를 { 북, 동, 남, 서} 로 설정
*
* 거북이가 지나간 영역을 모두 포함할 수 있는 가장 작은 직사각형의 넓이 구하기
* -> 최소 넓이를 구하기 위해서, 거북이가 이동한 좌표의 가장 끝과 끝점 구하기
* -> 각각 x좌표와 y좌표의 최대, 최소 위치값의 차이값을 곱하기
*/
int main() {
	int t;
	string str;

	// 입력
	cin >> t;
	while (t--) {
		cin >> str;
		// 계산 & 출력
		cout << getMinimumArea(str) << '\n';
	}
}