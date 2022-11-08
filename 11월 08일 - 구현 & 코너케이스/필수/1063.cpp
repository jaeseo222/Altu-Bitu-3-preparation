#include <iostream>

using namespace std;


int main()
{
	int sr, sc, kr, kc, nr, nc;
	int n;
	string a, b;
	cin >> a >> b >> n;

	kr = 9 - (a[1] - '0'), kc = a[0] - 'A' + 1;
	sr = 9 - (b[1] - '0'), sc = b[0] - 'A' + 1;

	while (n--) {
		string dir;
		cin >> dir;
		/*
		R : 한 칸 오른쪽으로
		L : 한 칸 왼쪽으로
		B : 한 칸 아래로
		T : 한 칸 위로
		RT : 오른쪽 위 대각선으로
		LT : 왼쪽 위 대각선으로
		RB : 오른쪽 아래 대각선으로
		LB : 왼쪽 아래 대각선으로
		*/

		if (dir == "R") {
			nr = 0, nc = 1;
		}
		else if (dir == "L") {
			nr = 0, nc = -1;
		}
		else if (dir == "B") {
			nr = 1, nc = 0;
		}
		else if (dir == "T") {
			nr = -1, nc = 0;
		}
		else if (dir == "RT") {
			nr = -1, nc = 1;
		}
		else if (dir == "LT") {
			nr = -1, nc = -1;
		}
		else if (dir == "RB") {
			nr = 1, nc = 1;
		}
		else if (dir == "LB") {
			nr = 1, nc = -1;
		}

		if (kr + nr <= 0 || kr + nr > 8 || kc + nc <= 0 || kc + nc > 8) {
			continue;
		}

		kr += nr;
		kc += nc;

		if (kr == sr && kc == sc) {
			if (sr + nr <= 0 || sr + nr > 8 || sc + nc <= 0 || sc + nc > 8) {
				kr -= nr;
				kc -= nc;
				continue;
			}
			sr += nr;
			sc += nc;
		}
	}
	cout << (char)(kc + 64) << 9 - kr << '\n' << (char)(sc + 64) << 9 - sr;
	return 0;
}
