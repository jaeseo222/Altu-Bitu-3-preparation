#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAX = 1001;

struct st {
    int cost, a, b; //cost=0 오르막길, cost=1 내리막길
};
vector<int> parent(MAX);
vector<st> tree;

bool cmp1(st a, st b){
    return a.cost < b.cost;
}

bool cmp2(st a, st b){
    return a.cost > b.cost;
}

int Find(int a){
    if(a== parent[a]){
        return a;
    }
    return parent[a] = Find(parent[a]);
}

void Union(int a , int b){
    int x = Find(a);
    int y = Find(b);
    parent[x] = y;
}

int solve(vector<st> &tree){
    int ans = 0;

    for(auto &i : tree){
        if(Find(i.a) != Find(i.b)){
            Union(i.a, i.b);

            if(!i.cost){
                ans++;
            }
        }
    }

    return ans;

}

int main(){

    int n, m;
    cin >>n>>m;

    for(int i=0 ; i<m +1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        tree.push_back({c, a, b});
    }

    //초기화
    for(int i=0; i<MAX ; i++){
        parent[i] = i;
    }

    sort(tree.begin(), tree.end(), cmp1); //오르막길 선택을 위한 정렬
    int max = solve(tree);

    //초기화
    for(int i=0; i<MAX ; i++){
        parent[i] = i;
    }

    sort(tree.begin(), tree.end(), cmp2); //내리막길 선택을 위한 정렬
    int min = solve(tree);

    //출력
    cout << (int)(pow(max,2) - pow(min, 2));

    return 0;
}