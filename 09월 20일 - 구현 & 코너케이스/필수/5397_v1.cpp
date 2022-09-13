#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char stack_left[1000001]; //커서 이전 내용을 저장
    char stack_right[1000001];//커서 이후 내용을 저장
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        int top_left = 0, top_right = 0;

        for (int i = 0; i < str.length(); ++i)
        {

            switch (str[i])
            {
            case ('<'): // 커서를 왼쪽으로 이동 -> dq.left의 마지막 원소를 dq_right 앞에 삽입
                if (top_left == 0)
                    break;
                stack_right[top_right++] = stack_left[--top_left];
                break;
            case ('>'): // 커서를 오른쪽으로 이동 -> stack_right의 처음 원소를 stack_left의 마지막에 삽입
                if (top_right == 0)
                    break;
                stack_left[top_left++] = stack_right[--top_right];
                break;
            case ('-'): //현재 커서 앞에 있는 글자를 지운다.
                if (top_left == 0)
                    break;
                --top_left;
                break;
            default: // 문자인 경우 커서보다 왼쪽에 입력하게 되므로 stack_left에 삽입
                stack_left[top_left++] = str[i];
            }
        }
        while (top_right) 
        {
            stack_left[top_left++] = stack_right[--top_right]; // stack_right의 마지막 원소부터 차례대로 stack_left에 삽입
        }
        stack_left[top_left] = '\0'; //문자열로 만들기 위해 마지막 원소를 '\0'로 삽입
        cout << stack_left << '\n'; // 문자열 출력
    }
    return 0;
}
