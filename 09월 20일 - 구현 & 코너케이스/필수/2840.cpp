#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    - 배열을 ?로 초기화 해주고, 입력대로 처리한다
    - 문제의 경우, 화살표를 고정시키고 바퀴를 돌리는데,
    - 풀 때에는 바퀴를 돌리고, 화살표를 고정시키는 방식으로 풀었다. (출력시 방향을 바꿔야함)
    <주의 사항>
    1. ?이 아닌 문자가 저장되어있는데, 다른 문자를 저장하려는 경우
    2. 룰렛에 중복되는 문자가 있는 경우
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //입력
    int n, k;
    cin >> n >> k;

    vector<char> arr(n, '?'); //?로 초기화

    int index = 0;
    while (k--) {
        int num;
        char ch;
        cin >> num >> ch;

        index = (index + num) % n;

        // 1번 조건 체크
        if (arr[index] != '?' && arr[index] != ch) {
            cout << "!\n";
            return 0;
        }

        arr[index] = ch;
    }

    // 2번 조건 체크
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] != '?' && arr[i] == arr[j]) {
                cout << "!\n";
                return 0;
            }
        }
    }

    //출력
    for (int i = n; i > 0; i--) {
        cout << arr[(i + index) % n];
    }
}