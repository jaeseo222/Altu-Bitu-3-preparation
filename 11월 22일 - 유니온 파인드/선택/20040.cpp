#include <iostream>
#include <vector>
using namespace std;

vector<int> parent; 

//Find 연산
int find(int x){
    if (parent[x] < 0) { 
        return x;
    }
    return parent[x] = find(parent[x]); 
}

//Union 연산
bool unionInput(int x, int y){
    int xp = find(x); 
    int yp = find(y);

    if (xp == yp){ //같은 트리에 속하는 경우 -> 사이클이다
        return false;
    }
    
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