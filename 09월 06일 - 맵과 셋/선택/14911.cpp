#include<iostream>
#include<map>

using namespace std;

int findPair(map<int,int> mp, int goal) {

    int result = 0;//조건을 만족하는 (a,b)의 개수

    //범위 기반 for문
    for (auto i : mp) {
        int temp = goal - i.first;
        //temp가 구하려는 값의 반보다 작다면 break -> 절반보다 큰 경우에만 고려하여 중복 제거
        if (temp < (goal + 1) / 2) {
            break;
        }
        mp[i.first]--;
        //temp크기의 숫자가 1개 이상 있다면 쌍 생성 가능
        if (mp[temp] > 0) {
            cout << i.first << " " << temp << "\n";
            mp[temp]--;
            result++;
        }
    }
    return result;
}

int main(void) {
    int num,goal;
    map<int, int> mp;

    //숫자를 입력 받는 동안 반복 -> 해당 숫자 개수 카운트
    while (cin >> num) {
        mp[num]++;
    }
    //원하는 합
    goal=num;
   
    cout << findPair(mp, goal);

}
