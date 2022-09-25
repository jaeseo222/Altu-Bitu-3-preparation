#include <iostream>
#include <deque>
using namespace std;

/**
 * [힌트] 벨트의 회전과 로봇의 이동을 인덱스로 관리해볼까요?
 * 1단계(rotate()): 벨트 회전 + n번째 칸 로봇 내리기
 * 2단계(move())  : 로봇 이동시키기 + n번째 칸 로봇 내리기
 * 3단계(put())   : 1번째 칸에 로봇 올리기
 */

struct info {
    int power;  //벨트의 내구도
    int robot;  //벨트 위 로봇 존재 여부(1: 존재O, 0: 존재X)
};

/** 1단계 */
void rotate(deque<info> &belt, int n) {
    //벨트 회전
    belt.push_front(belt.back());
    belt.pop_back();

    //n번째 칸 로봇 내리기
    if(belt[n-1].robot) {
        belt[n-1].robot--;    //로봇 내리기
    }
}

/** 2단계 */
void move(deque<info> &belt, int n) { //로봇 이동시키기
    /*
    * [로봇 이동을 위한 조건]
    * 1. 현재 칸에 로봇이 존재하고(belt[i].robot)
    * 2. 다음 칸에 로봇이 존재하지 않고(!belt[i+1].robot) 
    * 3. 다음 칸의 내구도가 1 이상일 때(belt[i].power)
    * 
    * 이때 가장 먼저 올라간 로봇은 가장 뒤에 존재! -> 뒤에서부터 접근하기
    */ 

    //맨 마지막 칸에 위치한 로봇 이동
    if(belt[2*n-1].robot && !belt[0].robot && belt[0].power) {
        belt[2*n-1].robot--;  //현재 칸 로봇 내리고
        belt[0].robot++;    //다음 칸에 로봇 올리고
        belt[0].power--;    //다음 칸의 내구도 1 감소
    }
    //나머지 칸 로봇 이동
    for(int i=2*n-2; i>0; i--) {   //먼저 올라간 로봇부터 옮기기 시작
        if(belt[i].robot && !belt[i+1].robot && belt[i+1].power) { //이동하려는 칸에 로봇이 없고 내구도가 1 이상이면 이동
            belt[i].robot--;
            belt[i+1].robot++;
            belt[i+1].power--;
        }
    }

    //n번째 칸 로봇 내리기
    if(belt[n-1].robot) {
        belt[n-1].robot--;
    }
}

/** 3단계 */
void put(deque<info> &belt) {
    //1번째 칸에 로봇 올리기
    if(belt[0].power) {
        belt[0].robot++;
        belt[0].power--;
    }    
}

int count_zero(deque<info> &belt, int n) { //벨트에서 내구도가 0인 칸 세기
    int cnt=0;
    for(int i=0; i<2*n; i++) {
        if(!belt[i].power) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin>>n>>k;
    deque<info> belt(2*n, {0,0});    //벨트 초기화
    for(int i=0; i<2*n; i++) {
        cin>>belt[i].power;
    }

    int stage=0;    //현재 진행 중인 단계
    do {
        rotate(belt, n);
        move(belt, n);
        put(belt);
        stage++;
    } while(count_zero(belt, n)<k);

    cout<<stage;

    return 0;
}
