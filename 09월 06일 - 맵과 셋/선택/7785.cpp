#include<iostream>
#include<set>

using namespace std;

int main() {
	int n;
	string name, state;
	set<string> company;

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> state;
		company.insert(name);

		if (state == "leave")
			company.erase(name);
	}

	// 출력 (역으로 참조)
	for (auto iter = company.rbegin(); iter != company.rend(); iter++) {
		cout << *iter << '\n';
	}
}