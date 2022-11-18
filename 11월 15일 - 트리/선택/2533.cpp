#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edges;
vector<bool> visit;
int dp[1000001][2]; //0 일 때 해당 정점이 얼리어답터 아닐 때, 1 일 떄 해당 정점이 얼리어답터 일 때

void solution(int x){

    visit[x]=true;
    dp[x][1] = 1 ;

    for(int i=0 ; i<edges[x].size(); i++){
        int child = edges[x][i];
        if (!visit[child]){
            solution(child);
            dp[x][0] += dp[child][1]; //현재 정점이 얼리어답터가 아닐 때,
            dp[x][1] += min(dp[child][0], dp[child][1]); //현재 정점이 얼리어답터일 때
        }
    }

}

int main() {

    //입력
    int n;
    cin >> n;

    edges.resize(n+1);
    visit.resize(n+1);
    int u, v;
    for(int i=1; i<n; i++){
        cin >> u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    //연산
    solution(1);

    //출력
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}