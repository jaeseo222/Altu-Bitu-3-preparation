#include <iostream>
#include <vector>

using namespace std;

//임의로 설정한 가로등의 높이와 가로등 사이의 거리를 비교해서 가로등 사이 밝히지 못한 구간이 있는지 확인.
int solution(int n, int m, vector<int> lights) {
    int start = 0;
    int end = n;

    while (start <= end) {
        int mid = (start + end) / 2;
        bool check = true; //모든 구간을 밝힐 수 있는가

        if (lights[0] > mid) { //시작 구간 확인
            check = false;
        }

        for (int i = 1; i < m; i++) { //가로등 사이 구간 확인
            if (lights[i] - lights[i - 1] > mid * 2) {
                check = false;
                break;
            }
        }

        if (n - lights[m - 1] > mid) { //끝 구간 확인
            check = false;
        }

        if (!check) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return start;
}

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<int> lights(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> lights[i];
    }

    //연산, 출력
    cout << solution(n, m, lights);

    return 0;
}