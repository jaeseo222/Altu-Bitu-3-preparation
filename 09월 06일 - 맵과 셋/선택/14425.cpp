#include<iostream>
#include<set>

using namespace std;

/**
* N,M <=10000 이므로 N개의 문자열을 벡터에 저장하고 존재 여부를 O(N)에 확인하면 시간초과 발생.
* 따라서 탐색 시간을 줄이기 위해 원소 탐색에 O(logN) 시간이 걸리는 이진트리 구조의 set을 사용한다.
*/

int main() {
	int n, m, cnt = 0;
	string str;

	set<string> s;
	cin >> n >> m;

	while (n--) {
		cin >> str;
		s.insert(str);
	}

	while (m--) {
		cin >> str;
		cnt += s.count(str);
	}
	cout << cnt;
}
