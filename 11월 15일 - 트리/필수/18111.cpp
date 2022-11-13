#include <iostream>
#include <vector>
using namespace std;

/*
    !주의! 당장 쌓을 블록이 없더라도 언젠가 다른 곳의 블록을 제거해서 쌓을 수 있음.
    시간을 최소로 하는 것이 우선되고, 소요 시간이 같을 경우 높이가 높은 것이 정답임
    => 소요 시간을 최소로 해야 하기 때문에, 완성된 땅의 높이는 입력받은 땅의 높이의 최솟값 ~ 최댓값 사이로 결정된다.
 */

const int INF = 1e9;

int minimumTime(int height, int block, int n, int m, vector<vector<int>> ground) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (height < ground[i][j]) { //블록 제거
                block += (ground[i][j] - height);
                time += 2 * (ground[i][j] - height);
            } else if (height > ground[i][j]) { //블록 추가
                block -= (height - ground[i][j]);
                time += (height - ground[i][j]);
            }
        }
    }

    if (block < 0) { //다 계산을 했는데 block이 음수이면 불가능한 경우
        return INF;
    }
    return time;
}

int main() {
    int n, m, b;
    cin >> n >> m >> b;
    vector<vector<int>> ground(n, vector<int>(m, 0));

    int maxh = 0, minh = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ground[i][j];
            maxh = max(maxh, ground[i][j]); // 제일 높은 곳의 높이
            minh = min(minh, ground[i][j]); // 제일 낮은 곳의 높이
        }
    }

    int max_height = 0;
    int min_time = INF;
    for (int h = minh; h <= maxh; h++) {
        int time = minimumTime(h, b, n, m, ground);
        if (time <= min_time) { // 최소 시간이 같을 경우, 최대 높이를 출력해야 하기 때문에 등호 필요
            min_time = time;
            max_height = h;
        }
    }

    cout << min_time << " " << max_height;
}