#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int check[9] = { false, };
int arr[8] = { 0, };
int num[8] = { 0, };

void backtracking(int cnt) {

	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}


	int before = -1;
	for (int i = 0; i < n; i++) {

		if (!check[i] && before != num[i]) { //바로 이전에 선택된 값이 이번 값과 동일하지 않을 경우만 재귀탐색 진행
			check[i] = true;
			before = num[i];
			arr[cnt] = num[i];
			permutaion(depth + 1);
			check[i] = false;
		}
	}
}
/**
* [N과 M (9)] - 백트래킹
* 이전 수열의 마지막 항과 새로 추가할 값이 같으면 중복된 수열이 된다는 점을 활용! 
* 기본 재귀 순열에서 이전에 선택된 값을 저장하기 위해 before라는 변수를 사용하여 
* depth번째에 같은 숫자가 중복되서 사용되지 않도록 함
*/
int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];

	}
		
	sort(num, num + n);

	backtracking(0);
}
