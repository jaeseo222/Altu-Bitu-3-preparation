#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

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
    vector<int> arr;
    int num,goal;
    map<int, int> mpair;


    //숫자를 입력 받는 동안 반복 -> arr에 삽입
    while (cin >> num) {
        arr.push_back(num);
    }
    goal = arr.back(); //원하는 합
    arr.pop_back();

    //숫자의 개수를 세는 map 생성
    for (int i = 0; i < arr.size(); i++) {
        mpair[arr[i]]++;
    }
   
    cout << findPair(mpair, goal);

}