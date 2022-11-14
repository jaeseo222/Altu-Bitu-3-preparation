#include<iostream>

using namespace std;
typedef pair<int, int> pi;
/*
 * hint: 차근차근 구현하면 될 것 같네요! 움직이지 않을 때의 조건을 꼼꼼하게 확인해주세요.
 * 입출력 형식을 확인해주세요
 */

pi nextCoord(string str, pi coord) {
	//다음 좌표 구하기
	pi res = coord;
	if (str == "R") {
		res.first++;
	}
	else if (str == "L") {
		res.first--;
	}
	else if (str == "B") {
		res.second--;
	}
	else if (str == "T") {
		res.second++;
	}
	else if (str == "RT") {
		res.first++; res.second++;
	}
	else if (str == "LT") {
		res.first--; res.second++;
	}
	else if (str == "RB") {
		res.first++; res.second--;
	}
	else if (str == "LB") {
		res.first--; res.second--;
	}
	return res;
}

bool inRange(int num) { //체스판 범위 벗어나는지 확인
	if (num <= 0 || num > 8) {
		return false;
	}
	return true;
}

void move(string str, pi &stone, pi &king) {

	pi next_king = nextCoord(str, king);
	if (!inRange(next_king.first) || !inRange(next_king.second)) {
		//king이 체스판을 벗어난 경우
		return;
	}
	//king이 체스판을 벗어나지 않는 경우
	if (next_king.first == stone.first && next_king.second == stone.second) {
		//king이 돌과 같은 곳으로 이동하는 경우
		pi next_stone = nextCoord(str, stone);
		if (!inRange(next_stone.first) || !inRange(next_stone.second)) {
			//돌이 체스판을 벗어나는 경우
			return;
		}
		stone = next_stone;
	}
	king = next_king;
}

int main() {
	string st, k;	int n;
	cin >> k >> st >> n;

	//돌, 킹의 좌표
	pi stone = { st[0] - 'A'+1, st[1]-'0'};
	pi king = { k[0] - 'A'+1, k[1]-'0'};

	//이동
	while (n--) {
		string str;
		cin >> str;
		move(str, stone, king);
	}
	//출력
	cout << char('A' + king.first - 1) << king.second << '\n';
	cout << char('A' + stone.first - 1) << stone.second;

}
