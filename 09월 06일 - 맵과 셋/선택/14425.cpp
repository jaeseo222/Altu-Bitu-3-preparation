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

int main() {
    string s; //입력(중위표기식)

    //입력
    cin >> s;

    //출력
    cout << infixToPostfix(s) << '\n';

    return 0;
}