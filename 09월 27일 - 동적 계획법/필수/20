#include <iostream>
#include <deque>

using namespace std;
// 그라운드에 있는 상대방 덱 (src1) 과 자신의 덱 (src2)을 자신의 덱(des)을 합치는 함수
void mergeCards(deque<int> &src1, deque<int> &src2, deque<int> &des)
{
    while (!src1.empty())
    {
        des.push_back(src1.back()); // 상대방덱을 뒤집어서(즉 맨 뒤부터) 아래로 힙치기
        src1.pop_back();
    }
    while (!src2.empty())
    {
        des.push_back(src2.back()); // 자신의 덱을 뒤집어서(즉 맨 뒤부터) 아래로 힙치기
        src2.pop_back();
    }
}

string playGame(int m, deque<int> &dodo, deque<int> &su)
{
    deque<int> do_gr; //그라운드에 있는 도도의 카드 더미
    deque<int> su_gr; // 그라운드에 있는 수연의 카드 더미
    bool flag = true; // true일 때는 도도의 차례, false 일 때는  수연의 차례

    while (m--)
    {
        if (flag)
        {
            do_gr.push_front(dodo.front()); // 덱에 있는 맨 위의 카드를 그라운드에 놓는다
            dodo.pop_front();
            if (dodo.empty())
                return "su"; // 덱에 있는 카드의 수가 0이 되면 상대방이 즉시 승리
        }
        else
        {
            su_gr.push_front(su.front()); /// 덱에 있는 맨 위의 카드를 그라운드에 놓는다
            su.pop_front();
            if (su.empty())
                return "do"; // 덱에 있는 카드의 수가 0이 되면 상대방이 즉시 승리
        }
        flag = !flag; //순서 바꾸기
        //도도와 수연이가 종을 칠 수 있는지 검사
        if (!do_gr.empty() && do_gr.front() == 5 || !su_gr.empty() && su_gr.front() == 5)
            mergeCards(su_gr, do_gr, dodo);
        if (!do_gr.empty() && !su_gr.empty() && do_gr.front() + su_gr.front() == 5)
            mergeCards(do_gr, su_gr, su);
    }

    if (dodo.size() > su.size())
        return "do";
    else if (dodo.size() < su.size())
        return "su";
    return "dosu";
}
/*
 *[숫자 할리갈리 게임] : 구현, 시뮬레이션
 * 도도,수연이의 덱과 그라운드에 있는 도도,수연의 덱 총 4개의 덱을 관리해주면 됩니다
 * deque 라이브러리를 사용하면 카드 덱에서 일어나는 일들을 쉽게 구현할 수 있습니다
 * 문제에서 주어진 게임 진행 순서대로 구현하면 됩니다
 * 주의할 점은 도도 또는 수연이의 덱에 카드가 없는 '즉시' 종료가 되는 것 입니다
 */
int main()
{
    int n, m;
    cin >> n >> m;
    deque<int> dodo;
    deque<int> su;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        dodo.push_front(a);
        su.push_front(b);
    }

    cout << playGame(m, dodo, su);
    return 0;
}
