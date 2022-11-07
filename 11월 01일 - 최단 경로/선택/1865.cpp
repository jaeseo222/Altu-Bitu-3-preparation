#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
typedef tuple<int, int, int> tp;


bool bellmanFord(int n,  vector<tp>& edges) {
 
    vector<int> dist(n + 1,0);

    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 0; j < edges.size(); j++) {
            //s->d인 간선의 가중치가 w
            int s = get<0>(edges[j]);
            int d = get<1>(edges[j]);
            int w = get<2>(edges[j]);

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
   
    return true;
}
/**
* [1865번 웜홀] 벨만 포드 
* 
* 시간이 줄어들면서 출발 위치로 돌아오는 것 = 음의 사이클이 존재. 
* 벨만포드는 출발점이 특정한 한 점일때 가능한 알고리즘.
* 그러나 특정 정점 하나만 확인하면 해당 정점과 단절된 노드가 포함된 음수 사이클을 발견할 수 없음.
* 따라서 1) 모든 정점에 대해서 벨만포드 알고리즘을 돌려서 음수 사이클이 발생하는지 확인 하거나
* 2) cycle의 형성 유무에 대해서 생각해보는 방법이 있다. 
* 사실 초깃값을 INF로 설정하는 이유는 단절된 경우의 경로는 배제시키고 , 어떤 지점까지의 거리를 구하기 위해서이다. 
* 따라서 만약 단순 그래프에서 사이클 유무만 파악할 때는 dist[]초기화를 어떤 값으로 해주어도 상관이 없다.
* 왜냐하면 거리를 구하는 것이 목적이 아닌, 음의 사이클 존재여부만 판별하고 싶기 때문이다.
* ! 무방향 그래프일때는 방향 그래프 두개로 쪼개서 생각하기!
*/
int main() {
    int tc, n, m, w, s, e, t;

    cin >> tc;

    while (tc--) {

        //입력
        cin >> n >> m >> w;
        vector<tp> edges; //간선 정보를 저장할 벡터

        //도로 입력
       while(m--){
            cin >> s >> e >> t;

            //무방향
            edges.push_back({ s, e, t });
            edges.push_back({ e, s, t });
        }
        
        //간선 입력
       while(w--){
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
