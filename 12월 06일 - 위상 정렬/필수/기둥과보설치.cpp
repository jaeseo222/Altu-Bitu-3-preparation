#include <iostream>
#include <string>
#include <vector>
using namespace std;
/** 구조물 설치 */
bool build(int n, vector<vector<vector<int>>> installed, int x, int y, int a) {
    if(a==0) { //기둥 설치
        // 1. 기둥이 바닥 위에 있는 경우
        if(y==0) { 
            return true;
        }
        // 2. 다른 기둥 위에 있는 경우
        if(y-1>=0 && installed[x][y-1][0]) { 
            return true;
        }
        // 3. 보의 왼쪽 끝 위에 있는 경우
        if(installed[x][y][1]) { 
            return true;
        }
        // 4. 보의 오른쪽 끝 위에 있는 경우
        if(x-1>=0 && installed[x-1][y][1]) { 
            return true;
        }
    } else { //보 설치
        // 1. 왼쪽 끝이 기둥 위에 있는 경우
        if(y-1>=0 && installed[x][y-1][0]) { 
            return true;
        }
        // 2. 오른쪽 끝이 기둥 위에 있는 경우
        if(x+1<=n && y-1>=0 && installed[x+1][y-1][0]) { 
            return true;
        }
        //3. 양쪽 끝이 다른 보와 동시에 연결된 경우
        if((x-1>=0 && installed[x-1][y][1]) && (x+1<=n && installed[x+1][y][1])) { 
            return true;
        }
    }
    return false;
}
/** 구조물 삭제*/
bool remove(int n, vector<vector<vector<int>>> installed, int x, int y, int a) {
    bool flag=true;
    installed[x][y][a]=0; // 현재 구조물 삭제
    if(a==0) { // 기둥 삭제
        if(x-1>=0 && y+1<=n && installed[x-1][y+1][1] && !build(n, installed, x-1, y+1, 1)) {
            flag=false;
        }
        else if(y+1<=n && installed[x][y+1][1] && !build(n, installed, x, y+1, 1)) {
            flag=false;
        }
        else if(y+1<=n && installed[x][y+1][0] && !build(n, installed, x, y+1, 0)) {
            flag=false;
        }
    } else { // 보 삭제
        if(x-1>=0 && installed[x-1][y][1] && !build(n, installed, x-1, y, 1)) {
            flag=false;
        }
        else if(x+1<=n && installed[x+1][y][1] && !build(n, installed, x+1, y, 1)) {
            flag=false;
        }
        else if(installed[x][y][0] && !build(n, installed, x, y, 0)) {
            flag=false;
        }
        else if(x+1<=n && installed[x+1][y][0] && !build(n, installed, x+1, y, 0)) {
            flag=false;
        }
    }
    if(!flag) {
        installed[x][y][a]=1;
    }
    return flag;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<vector<int>>> installed=vector<vector<vector<int>>> (n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));
    for(int i=0; i<build_frame.size(); i++) {
        int x=build_frame[i][0];
        int y=build_frame[i][1];
        int a=build_frame[i][2];
        int b=build_frame[i][3];
        if(b==0) { // 구조물 삭제
            if(remove(n, installed, x, y, a)) {
                installed[x][y][a] = 0;
            }
        } else { // 구조물 설치
            if(build(n, installed, x, y, a)) {
                installed[x][y][a] = 1;
            }
        }
    }
    // 결과 붙여넣기
    vector<vector<int>> answer;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            for(int a=0; a<2; a++) {
                if(installed[i][j][a]) {
                    answer.push_back({i, j, a});
                }
            }
        }
    }
    return answer;
}
/**
 * [구조물 설치]
 * 1. 기둥 설치 조건
 *    - 기둥이 바닥 위에 있거나
 *    - 다른 기둥 위에 있거나
 *    - 다른 보의 왼쪽 끝 위에 있거나
 *    - 다른 보의 오른쪽 끝 위에 있어야 함
 * 2. 보 설치 조건
 *    - 보의 왼쪽 끝이 기둥 위에 있거나
 *    - 보의 오른쪽 끝이 기둥 위에 있거나
 *    - 보의 양쪽 끝이 다른 보와 연결되어 있어야 함
 * 
 * [구조물 삭제]
 * 1. 구조물 삭제
 * 2. 구조물 삭제했을 때 삭제하려는 구조물과 연결되어 있는 구조물들이 
 *    조건에 만족하는지(설치 가능한지) 확인
 * 3. 설치 불가능하면 구조물 삭제 취소
 */
int main() {
    int n = 5;
    vector<vector<int>> build_frame = {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}};
    vector<vector<int>> answer = solution(n, build_frame);
    
    for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i][0] << "\t" << answer[i][1] << "\t" << answer[i][2];
            cout << endl;
        }
    return 0;
}