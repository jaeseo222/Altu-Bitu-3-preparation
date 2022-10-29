#include <iostream>
#include <vector>

using namespace std;

//모든 구간을 밝힐 수 있는지 확인하는 함수
bool check(int n, int m, vector<int> &lamp, int mid) {

    if (lamp[0] > mid) { //시작 구간 확인
        return false;
    }

    for (int i = 1; i < m; i++) { //가로등 사이 구간 확인
        if (lamp[i] - lamp[i - 1] > mid * 2) {
            return false;
        }
    }

    if (n - lamp[m - 1] > mid) { //끝 구간 확인
        return false;
    }
    return true;
}

//임의로 설정한 가로등의 높이와 가로등 사이의 거리를 비교해서 가로등 사이 밝히지 못한 구간이 있는지 확인.
int parametricSearch(int n, int m, vector<int> &lamp, int left, int right) {

    while (left <= right) {
        int mid = (left + right) / 2;

        if (!check(n, m, lamp, mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right + 1;
}

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<int> lamp(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> lamp[i];
    }

    //연산, 출력
    cout << parametricSearch(n, m, lamp, 0, n);

    return 0;
}