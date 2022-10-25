#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
typedef tuple<int, int, int> tp;

const int INF = 5e6; //최대 n-1개의 간선을 지나게 됨 -> n * (가중치 최대값)

bool bellmanFord(int n,  vector<tp>& edges) {
 

    vector<int> dist(n + 1, 0);

    //모든 정점에 대해 벨만포드 
    for (int s = 1; s <= n; s++) {
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int j = 0; j < edges.size(); j++) {
                //s->d인 간선의 가중치가 w
                int s = get<0>(edges[j]);
                int d = get<1>(edges[j]);
                int w = get<2>(edges[j]);
             
                if (dist[s] == INF) { //아직 시작점에서 s로 가는 경로가 발견되지 않았으므로 갱신할 수 없음
                    continue;
                }
                int next_weight = dist[s] + w;
           

                if (next_weight < dist[d]) {
                    flag = false;

                    dist[d] = next_weight;

                    if (i == n) { //n번째 단계에서 최단 거리 테이블 갱신 -> 음의 사이클 발생 확인

                        return false;

                    }
                }
            }

            if (flag) {
                break;
            }
        }
   
   
    }
   
    return true;
}
/**
* [1865번 웜홀] 벨만 포드 
* 
* 시간이 줄어들면서 출발 위치로 돌아오는 것 = 음의 사이클이 존재. 
* 특정 정점 하나만 확인하면 해당 정점과 연결되어 있지 않은 노드가 있을때 그 노드의 음수 사이클을 벨만포드 알고리즘으로 발견 할 수 없다
* => 따라서 모든 정점을 시작점으로 하여 벨만 포드 연산 수행하여 음의 사이클이 발생하는지 확인한다.
* ! 무방향 그래프일때는 방향 그래프 두개로 쪼개서 생각하기!
* 
*/
int main() {
    int tc, n, m, w, s, e, t;

    cin >> tc;

    while (tc--) {

        //입력
        cin >> n >> m >> w;
        vector<tp> edges; //간선 정보를 저장할 벡터

        //도로 입력
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;

            //무방향
            edges.push_back({ s, e, t });
            edges.push_back({ e, s, t });
        }
        
        //간선 입력
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;

            //단방향
            edges.push_back({ s, e, -t });      
        }


        //연산 및 출력

        if (bellmanFord( n, edges)) { //음의 사이클
            cout << "NO\n"; 

        }
        else {
            cout << "YES\n";

        }
    

   
    }
}
