#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> arr;
int dr[2] = {1, 0};
int dc[2] = {0, 1};

int countCandy(int row, int col, int dir) {
    int result = 0, cnt = 0;
    char cur = ' ';
    for (int i = 0; i < n; i++) {
        if (cur == arr[row][col]) { //연속된 사탕
            cnt++;
            result = max(result, cnt);
        } else { //불연속
            cnt = 1;
            cur = arr[row][col];
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

int main() {
    // 입력
    cin >> n;
    arr.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // swap 해서 사탕 체크
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) { // j+1과 swap해야 하기 때문
            //좌우
            swap(arr[i][j], arr[i][j + 1]);
            result = max(result, findCandy());
            swap(arr[i][j], arr[i][j + 1]);

            //위아래
            swap(arr[j][i], arr[j + 1][i]);
            result = max(result, findCandy());
            swap(arr[j][i], arr[j + 1][i]);
        }
    }

    // 결과 출력
    cout << result;
    return 0;
}