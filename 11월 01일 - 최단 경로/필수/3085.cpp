#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
입력 범위가 작으므로, 사탕을 전부 바꿔보며 계산하자
*/

int n;
vector<string> arr;
int dr[2] = {1, 0};
int dc[2] = {0, 1};

int countCandy(int row, int col, int dir) {
    int result = 0, cnt = 0;
    char prev = ' ';
    for (int i = 0; i < n; i++) {
        if (prev == arr[row][col]) { //연속된 사탕
            cnt++;
            result = max(result, cnt);
        } else { //불연속
            cnt = 1;
            prev = arr[row][col];
        }
        row += dr[dir];
        col += dc[dir];
    }
    return result;
}

int findCandy() {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, countCandy(0, i, 0)); //같은 열
        result = max(result, countCandy(i, 0, 1)); //같은 행
    }
    return result;
}

int switchCandy(int row, int col, char candy) {
    int result = 0;
    for (int i = 0; i < 2; i++) {
        int nr = row + dr[i], nc = col + dc[i];
        if (nr < n && nc < n && candy != arr[nr][nc]) {
            swap(arr[row][col], arr[nr][nc]);
            result = max(result, findCandy());
            swap(arr[row][col], arr[nr][nc]);
        }
    }
    return result;
}

int main() {
    // 입력
    cin >> n;
    arr.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, switchCandy(i, j, arr[i][j]));
        }
    }

    // 결과 출력
    cout << result;
    return 0;
}