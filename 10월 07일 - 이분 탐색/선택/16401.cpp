#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//조카 1명에게 줄 수 있는 과자의 최대 길이 구하는 함수
int findMax(vector<int> snack_len, int left, int right, int m){
    int ans = 0;

    //이분탐색
    while (left <= right) {
        int mid = (left + right) / 2; //mid를 과자조각 최대 길이라고 가정
        int cnt = 0; //만들 수 있는 과자조각 수

        for (int i = 0; i < snack_len.size(); i++) {
            cnt += snack_len[i] / mid; //최대길이(mid)만큼 만들 수 있는 조각의 수
        }
        if (cnt >= m) { //과자조각 수 > 조카 수 -> 최대 길이 갱신
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}

int main(){
    //입력
    int m,n; //조카 수, 과자 수
    cin>>m>>n;
    vector<int> snack_len(n, 0); //과자 길이 배열 L
    for(int i=0;i<n;i++){
        cin>>snack_len[i];
    }

    sort(snack_len.begin(), snack_len.end()); //오름차순 정렬

    int min_len = 1, max_len = snack_len[n-1];  //과자조각의 최소, 최대 길이

    //연산, 출력
    cout<<findMax(snack_len, min_len, max_len, m)<<'\n';

    return 0;
}