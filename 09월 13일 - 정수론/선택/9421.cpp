#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

void isPrime(int n, vector<bool> &is_prime) {//에라토스테네스의 체 
	//0과 1은 소수가 아니므로 먼저 제거
	is_prime[0] = is_prime[1] = false;
	//2~제곱근 n까지 검사
	for (int i = 2; i <= sqrt(n); i++) {
		if (is_prime[i]) {//i가 소수라면
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;//i의 배수를 제거
			}
		}
	}
}


int calSumNum(int n) {//n의 각 자릿수의 제곱을 더한 값  sum을 반환하는 함수
	int sum = 0;
	while (n) {
		sum += pow(n % 10, 2);
		n /= 10;
	}
	return sum;
}

void isAnswer(int n, vector<bool>& is_prime, vector<int>& answer) {
	//답이 되기 위해서는 소수이면서 상근수여야 해요. 소수인지 판단한 결과는 is_prime에 저장되었답니다.
	//정수 n의 각 자릿수를 더하는 계산을 반복하면서 결과가 1이 나오면 상근수이고 그 전에 나온 결과가 다시 나온다면 상근수가 아니에요
	
	set<int> s;//전에 나온 결과를 저장하고 탐색까지 할 수 있는 set을 사용해요

	for (int i = 2; i < n; i ++ ) {
		if (is_prime[i]) { //i가 소수라면
			int tmp = i; //i는 반복문 조건에 사용되므로 값의 변화를 방지 하기 위해 새로운 변수에 저장해요
			while (1) {

				tmp = calSumNum(tmp); //calSumNum함수를 통해 각 자릿수 제곱의 합을 tmp에 저장해요

				if (tmp == 1) {//자릿수의 합이 1이면
					answer.push_back(i);//답에 저장하고
					break;//반복문을 빠져나가요
				}
				
				if (s.find(tmp) != s.end()) { //자릿수 제곱의 합이 그 전에 결과와 같다면
					break;//반복문을 빠져나가요
				}
				s.insert(tmp);//자릿수의 합이 1도 아니고 전 결과와 겹치지 않으면 s에 삽입하고 반복문의 처음으로 돌아가요
			}
		}
		s.clear();//다음 정수를 판단하기 전에 꼭 s를 비워야해요
	}
}


int main() {
	int n;

	cin >> n;

	vector<bool> is_prime(n + 1, true); // 소수인지 판단한 bool값 저장할 배열
	vector<int> answer; //소수 상근수 저장할 배열

	isPrime(n, is_prime);//소수인지 판단
	isAnswer(n, is_prime, answer);//소수 상근수인지 판단

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}