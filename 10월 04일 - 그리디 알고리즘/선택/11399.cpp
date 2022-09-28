

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> withdraw_time;

//첫번째 풀이 -> 시간복잡도 : O(n^2)
int calcTime(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) { //i번째 사람의 대기시간은 0, 1,...,i - 1, i번째 사람의 인출 시간은 합한 값
        for (int j = 0; j <= i; j++)
            sum += withdraw_time[j];
    }
    return sum;
}

//두번째 풀이 -> 시간복잡도 : O(n)
int calcTimeAdv(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += (withdraw_time[i] * (n - i));
    return sum;
}

/**
  [11399번 ATM ] 

 1. 문제 접근 방식 
모든 사람들의 대기시간의 합이 최소가 되기 위해서는
인출하는데 필요한 시간이 적은 사람이 맨 앞에 서야한다.
따라서 인출시간을 오름차순 정렬 시킨 후 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구해준다. 

2. 구현 방식
 
두가지 풀이 방법이 존재할 수 있는데, 

첫번째 풀이는 i번째 사람의 대기시간은 0, 1,...,i - 1 번째 사람의 인출 시간은 합한 값이라는 점을 활용해 
각 사람의 대기시간을 구해 각각 더해주는 방식이다. 시간복잡도는 O(N^2)이다.
ex)  1 + (1+2) + (1+2+3) + (1+2+3+3) + (1+2+3+3+4)  --- ㄱ 


두번째 풀이는 각 사람이 얼마나 대기해야하는지 관점이 아니라, 각 사람의 인출시간이 전체 인출시간에 얼만큼 영향을 미칠지의 관점에서 생각한 풀이이다.
인출하는데 걸리는 시간은 누적해서 더해지는 것이므로 앞선 첫번째 방식보다 시간복잡도를 개선할 수 있다. O(N)



식 ㄱ의 형태를 조금 변형하면

1
1 2 
1 2 3
1 2 3 3 
1 2 3 3 4 

즉, 사람이 n명일때 1번 사람의 인출시간은 n번 더해지고, 2번 사람의 인출시간은 n-1번 더해지고.. 
n번  사람의 인출시간은 1번 더해진다는 것을 알 수 있다.  ( 1번 사람은 withdraw_time의 0번 인덱스 임에 유의!)

ex)  1*5 + 2*4 + 3*3 + 3*2 + 4*1
 */
int main() {
    int n;

    //입력
    cin >> n;
    withdraw_time.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> withdraw_time[i];

    //연산
    sort(withdraw_time.begin(), withdraw_time.end());

    //출력
    cout << calcTimeAdv(n);
}
