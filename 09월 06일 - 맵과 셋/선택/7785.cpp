#include<iostream>
#include<set>

using namespace std;

int main() {
	int n;
	string name, state;
	set<string> company;

	// 입력
	cin >> n;
	while (n--) {
		cin >> name >> state;

		if (state == "enter")
			company.insert(name);
		else
			company.erase(name);
	}

	// 출력 (역으로 참조)
	for (auto iter = company.rbegin(); iter != company.rend(); iter++) {
		cout << *iter << '\n';
	}
}