#include<iostream>
#include<set>

using namespace std;

int main() {
	int n, m, cnt = 0;
	string s;'

	set<string> str;
	cin >> n >> m;

	while (n--) {
		cin >> s;
		str.insert(s);
	}

	while (m--) {
		cin >> s;
		cnt += str.count(s);
	}
	cout << cnt;
}
