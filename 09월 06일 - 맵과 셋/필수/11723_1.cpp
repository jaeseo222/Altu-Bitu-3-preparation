#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 21;
/*
 * vector 사용 풀이
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> s(SIZE, false); // 0~20의 유무를 나타낼 배열을 false로 초기화
    int m;

    cin >> m;
    while (m--)
    {
        string command;
        cin >> command;
        if (command == "all")
        {
            s.assign(SIZE, true); // true의 값으로 SIZE개의 원소를 할당
        }
        else if (command == "empty")
        {
            s.assign(SIZE, false);
        }
        else
        {
            int x;
            cin >> x;
            if (command == "add")
            {
                s[x] = true;
            }
            if (command == "remove")
            {
                s[x] = false;
            }
            if (command == "check")
            {
                cout << s[x] << '\n'; // true이면 1을, false이면 0을 출력
            }
            if (command == "toggle")
            {
                s[x] = !s[x]; // true이면 false를, false면 true를 대입
            }
        }
    }
    return 0;
}
