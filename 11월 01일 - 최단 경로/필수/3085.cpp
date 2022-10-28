#include <algorithm>
#include <iostream>

using namespace std;

int N;
string arr[50];

int count_candy_column(int column) { // 한 열에 있는 사탕 수 세기(상하)
    int result = 1;
    int alpha = 1;
    for (int i = 0; i < N - 1; i++) {
        if (arr[i][column] == arr[i + 1][column]) {
            alpha++;
        } else {
            result = max(result, alpha);
            alpha = 1;
        }
    }

    result = max(result, alpha);
    return result;
}

int count_candy_row(int row) { // 한 행에 있는 사탕 수 세기(좌우)
    int result = 1;
    int alpha = 1;
    for (int i = 0; i < N - 1; i++) {
        if (arr[row][i] == arr[row][i + 1]) {
            alpha++;
        } else {
            result = max(result, alpha);
            alpha = 1;
        }
    }

    result = max(result, alpha);
    return result;
}

int count_candy() {
    int result = 0;
    for (int i = 0; i < N; i++) {
        result = max(result, count_candy_column(i));
        result = max(result, count_candy_row(i));
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 최초 배열에서 최댓값 찾아두기
    int result = count_candy();
    if (result == N) {
        cout << result;
        return 0;
    }

    // swap 해서 사탕 체크
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) { // j+1과 swap해야 하기 때문
            //좌우
            swap(arr[i][j], arr[i][j + 1]);
            result = max(result, count_candy());
            swap(arr[i][j], arr[i][j + 1]);

            //위아래
            swap(arr[j][i], arr[j + 1][i]);
            result = max(result, count_candy());
            swap(arr[j][i], arr[j + 1][i]);
        }
    }

    cout << result;
    return 0;
}