#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int findPair(vector<int> arr, int goal) {
    //중복 확인을 위한 map 생성
    //pair (a,b)가 조건을 만족하는 쌍이면 map의 value로 true값을 저장
    map<pair<int, int>, bool> visited;

    int result = 0;//조건을 만족하는 (a,b)의 개수
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == goal && !visited.count({ arr[i],arr[j] })) {
                cout << arr[i] << " " << arr[j] << "\n"; //숫자쌍 출력
                visited[{arr[i], arr[j]}] = true;
                result++;
            }
        }
    }
    return result;
}
int main(void) {
    vector<int> arr;
    int num;

    //숫자 입력
    //입력 받는 숫자의 개수가 주어지지 않았음->EOF(end of file)이 발생할때까지 입력받음
    while (scanf("%d", &num) != EOF) {
        arr.push_back(num);
    }
    int goal = arr.back(); //원하는 합
    arr.pop_back();

    //오름차순 정렬
    sort(arr.begin(), arr.end());

    //출력
    cout << findPair(arr, goal);

}
