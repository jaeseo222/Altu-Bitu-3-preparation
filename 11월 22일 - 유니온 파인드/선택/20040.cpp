#include <iostream>
#include <vector>
using namespace std;

vector<int> parent; //부모 노드를 가리키는 벡터

//Find 연산: x가 포함된 트리를 찾음
int find(int x){
    if (parent[x] < 0) { //자기자신이 루트인 경우
        return x;
    }
    return parent[x] = find(parent[x]); //부모 노드 리턴
}

//Union 연산: x,y가 포함된 트리를 합침
bool unionInput(int x, int y){
    int xp = find(x); //x,y가 속한 트리의 루트 노드
    int yp = find(y);

    if (xp == yp){ //같은 트리에 속하는 경우 -> 사이클이다
        return false;
    }
    //다른 트리에 속하는 경우
    if (parent[xp] < parent[yp]){
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else{
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}


int main() {
    int n, m, x, y;

    //입력
    cin >> n >> m;
    parent.assign(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;

        //연산 & 출력
        if (!unionInput(x, y)) { //사이클 생성
            cout << i + 1;
            return 0;
        }
    }
    cout << 0; //사이클 생성x
    return 0;
}