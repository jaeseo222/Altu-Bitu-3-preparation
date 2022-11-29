#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


//위상정렬
vector<int> topologicalSort(int t, int n, vector<int> &indegree,  vector<vector<int>> &resources,  vector<vector<int>> &graph) {
    queue<pair<int, int>> q; //first:건물, second:시간
    vector<bool> check(n + 1, false); //  현황 
    vector<int> result;

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) {
            q.push({i, 0});
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int curr_t = q.front().second;
        q.pop();

        if (curr_t > t) {
            break;
        }
        result.push_back(x);
        for (int i = 0; i < resources[x].size(); i++) {
            int resource = resources[x][i];
            
             // 서로 다른 건물끼리 생산하는 자원이 겹칠 수 있으므로, 
             // 이미 확보한 자원으로는 중복해서 재료를 충족했다고 
            if (check[resource]) {
                continue;
            }
           
            check[resource] = true; // 리소스 확정 
            
            // 해당 resource를 재료로 하는 건물 목록 순회 
            for (int j = 0; j < graph[resource].size(); j++) { 
                int building = graph[resource][j]; 
                indegree[building]--; // 재료가 하나 충족되었으므로 진입차수 감소
                if (!indegree[building]) { // 재료를 모두 충족시키면
                    q.push({building, curr_t + 1});
                }
            }
        }
    }
    return result;
}

/**
 * [쿠키런 킹덤]
 *
 * 건물마다 필요로 하는 자원의 관계를 그래프로 표현하여 위상정렬 수행
 * 건물은 자원을 생성하고, 명시된 자원이 모두 충족되면 건물을 지을 수 있다 : 건물 -> 자원 -> 건물
 * => graph[i][j] : 건물 j 를 짓기 위해 자원 i가 필요함, i->j
 * - 초기에 이미 지어진 건물들이 생산하는 재료들로 새로운 건물들을 지어 새로운 자원을 확보하고, 
 * - 새롭게 확보된 자원으로 인해 재료가 모두 충족된 또 다른 건물을 연속적으로 지어나감
 * - 자원 하나를 확보할때마다, 해당 자원을 재료로 하는 건물들의 indegree값 감소 
 * - indegree가 0이되었다 => 자원을 모두 확보했다.
 * - 자원은 건물을 통해 무제한으로 만들 수 있으므로, 현재 보유한 건물이 생산하는 자원은 모두 해결됨
 * - 위상정렬하다 제한 시간을 넘으면 종료 
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t, cnt, resource, building;

    //입력
    cin >> n >> m >> t;
    vector<int> indegree(n + 1, 0); // indegree[i] : 건물 i 를 짓기 위해 필요한 자원의 갯수
    vector<vector<int>> graph(n + 1, vector<int>(0)); // graph[i][j] : 건물 j 를 짓기 위해 자원 i가 필요함, i->j
    vector<vector<int>> resources(n + 1, vector<int>(0)); // 각 건물이 생산하는 자원목록
    for (int i = 0; i < m; i++) { //이미 지어진 건물
        cin >> building;
    }
    for (int i = 1; i <= n; i++) { //건물이 생산하는 자원
        cin >> cnt;
        while (cnt--) {
            cin >> resource;
            resources[i].push_back(resource);
        }
    }
    for (int i = 0; i < n - m; i++) { //건물마다 필요한 자원
        cin >> building >> cnt;
        indegree[building] = cnt;
        while (cnt--) {
            cin >> resource;
            graph[resource].push_back(building);
        }
    }

    //연산
    vector<int> result = topologicalSort(t, n, indegree, resources, graph);
    sort(result.begin(), result.end());

    //출력
    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}
