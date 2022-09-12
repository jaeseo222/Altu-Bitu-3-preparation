#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

void isPrime(int n, vector<bool> &is_prime) {//에라토스테네스의 체 

	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i <= sqrt(n); i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
}


int calSumNum(int n) {//각 자릿수의 제곱을 더한 값 구하는 함수
	int sum = 0;
	while (n) {
		sum += pow(n % 10, 2);
		n /= 10;
	}
	return sum;
}


bool isSangguen(int n) {

	set<int> s;//저장한 숫자를 key로 탐색할 수 있는 set을 사용 (vs 배열은 인데스 형태이기에 저장된 숫자를 key로 탐색하기 어려워요)
	int tmp = n;
	while (1) {

		tmp = calSumNum(tmp); //각 자릿수 제곱의 합 구하기

		if (tmp == 1) {// 상근수이면
			return true;
		}
		if (s.find(tmp) != s.end()) { //상근수가 아니면
			return false;
		}
		s.insert(tmp);
	}
}


vector<int> Solution(int n) {

	vector<bool> is_prime(n + 1, true);
	vector<int> answer;
	isPrime(n, is_prime);

	for (int i = 2; i < n; i ++ ) {
		if (!is_prime[i]) continue; //소수 판단
		else{ 
			if (!isSangguen(i)) {//상근수 판단
				continue;
			}
			else {
				answer.push_back(i);
			}
		}
	}
	return answer;
}

/*
* isPrime함수로 소수인지 판단하고
* isSangguen함수로 상근수인지 판단해요. 상근수 판단 시에는 상근수일 조건 + 상근수가 아닌 조건을 생각해주세요
*/

int main() {
	int n;

	cin >> n;

	 vector<int> v = Solution(n);

	for (int i = 0; i <v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}
