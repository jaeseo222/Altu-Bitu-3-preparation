#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e6;

//에라토스테네스의 체, 미리 SIZE까지의 소수 판단
vector<bool> isPrime() {
    vector<bool> is_prime(MAX + 1, true); 

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (!is_prime[i]) {
            continue;
        }
     
        for (int j = i * i; j <= MAX; j += i) {
            is_prime[j] = false; 
        }
    }
    return is_prime;
}


int goldbach(int n, vector<bool>& is_prime) {

    for (int i = 3; i <= n / 2; i += 2) { //홀수만검사, n/2 이상의 값은 어차피 n-i를 통해 검사되므로 n/2까지 검사
        if (is_prime[i] && is_prime[n - i]) { //하나의 소수가 정해지면(i) 나머지 하나의 소수는 n-i로 자동 결정 -> 둘다 소수라면
            return i; //두 홀수 소수 중 더 작은 값 리턴
        }
    }
    return 0; //골드바흐의 추측이 틀린 경우 false 리턴
}

int main() {
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    
    int n;

    vector<bool> is_prime = isPrime();

    while (true) {

        //입력
        cin >> n;
        if (n == 0)
            break;

      
        int prime  = goldbach(n, is_prime); 
        if (prime) {
            cout << n << " = " << prime << " + " << n - prime << '\n';
        }
        else {
            cout << "Goldbach's conjecture is wrong.\n";
        }
            

    }
 
 
}
