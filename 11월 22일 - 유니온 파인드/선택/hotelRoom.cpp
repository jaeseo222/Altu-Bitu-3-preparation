#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

unordered_map <ll, ll> rooms;

ll find(ll num) {
    if (rooms[num] == 0) { // 방이 비어있다면
        return num;
    }
    else {
        return rooms[num] = find(rooms[num]);
    }
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for (ll num : room_number) {
        ll x = find(num); // x: 배정된 방 번호
        answer.push_back(x);
        rooms[x] = x + 1; // 다음 방을 가리키도록 
    }
    return answer;
}
/**
 * [프로그래머스 - 호텔 방 배정]
 *
 * rooms 라는 map을 만들어 각 호텔당 투숙객 정보 저장
 * 이때 key: 방 번호, value: 해당 방 다음에 있는 가장 가까운 빈 방 으로 설정하여
 * 원하는 방이 이미 배정되어있다면, 바로 다음 방을 탐색할 수 있도록 함.
 * 이때 그냥 map을 사용하면 시간초과, 탐색속도를 높이기 위해 Hash 방식으로 구현된 unordered_map 사용. 
 *
 */

// 프로그래머스 실행을 위한 메인 함수
int main() {
    ll k = 10;
    vector<ll> room_number = {1, 3, 4, 1, 3, 1};
    vector<ll> result = solution(k, room_number);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}

