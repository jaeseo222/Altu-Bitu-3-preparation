#include<iostream>
#include<deque>
#include<vector>
using namespace std;
/*
* 힌트: 어떤 자료구조를 사용하는 게 좋을까요?
*/

typedef pair<int, int> pi;
typedef vector<deque<int>> vd;

void getCard(vd& deck, vd& ground, int player) {
    //상대방 그라운드에 있는 카드 더미를 자신의 덱에 합친다
    while (!ground[1 - player].empty()) {
        deck[player].push_back(ground[1 - player].back());
        ground[1 - player].pop_back();
    }
    //자신의 그라운드에 있는 카드 더미도 자신의 덱에 합친다
    while (!ground[player].empty()) {
        deck[player].push_back(ground[player].back());
        ground[player].pop_back();
    }
}

void check5(vd& deck, vd& ground) {
    //5가 나오는 경우
    if ((!ground[0].empty() && ground[0].front() == 5) || (!ground[1].empty() && ground[1].front() == 5)) {
        getCard(deck, ground, 0);
        return;
    }
    //합이 5인 경우
    if (!ground[0].empty() && !ground[1].empty() && (ground[0].front() + ground[1].front() == 5)) {
        getCard(deck, ground, 1);
        return;
    }
}

int checkResult(vd& deck) {
    if (deck[0].size() > deck[1].size()) {
        return 0;
    }
    if (deck[0].size() < deck[1].size()) {
        return 1;
    }
    return -1;
}


//0을 리턴하면 도도, 1을 리턴하면 수연이 이김. 비기면 -1 리턴
int play(vd &deck, vd& ground, int m) { 
    for (int i = 0; i < m; i++) {
        //turn이 0이면 도도, 1이면 수연이 차례
        int turn = i % 2; 
        //한 개씩 카드를 뽑아서 그라운드에 놓는다.
        ground[turn].push_front(deck[turn].front());
        deck[turn].pop_front();

        //더이상 뽑을 카드가 없는 경우 - 게임 종료
        if (deck[turn].empty()) {
            //cout << "no card\n";
            return 1 - turn;
        }
        //5가 나오거나, 합이 5인 경우 체크
        check5(deck, ground); 
    }
    return checkResult(deck);
}

int main() {
	int n, m;
    vd deck(2), ground(2);

	cin >> n >> m;
	while (n--) {
		int num1, num2;
		cin >> num1 >> num2;
		deck[0].push_front(num1);
		deck[1].push_front(num2);
	}

    int res = play(deck, ground, m);
    if (res==1) {
        cout << "su\n";
    }
    else if (res == 0) {
        cout << "do\n";
    }
    else {
        cout << "dosu\n";
    }

}
