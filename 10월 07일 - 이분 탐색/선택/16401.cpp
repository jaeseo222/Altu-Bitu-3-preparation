#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//최대 길이(len)만큼 만들 수 있는 과자조각의 수 구하는 함수(이분탐색에서 사용)
int snackNum(vector<int> snack_len, int len) {
    int cnt = 0; //만들 수 있는 과자조각 수

    for (int i = 0; i < snack_len.size(); i++) {
        if (snack_len[i] < len) break; // len보다 과자 길이가 작아지면 탈출
        cnt += snack_len[i] / len; 
    }
    return cnt;
}

//조카 1명에게 줄 수 있는 과자조각의 최대 길이 구하는 함수
int parametricSearch(vector<int> snack_len, int left, int right, int m){
    int ans = 0;

    //이분탐색
    while (left <= right) {
        int mid = (left + right) / 2; //mid를 과자조각 최대 길이라고 가정

        int cnt = snackNum(snack_len, mid); //최대길이(mid) 만큼 만들 수 있는 과자조각의 수

        if (cnt >= m) { //과자조각 수 >= 조카 수 -> 최대 길이 갱신
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

    sort(snack_len.begin(), snack_len.end(), greater<>()); //내림차순 정렬
    int min_len = 1, max_len = snack_len[0];  //과자조각의 최소, 최대 길이
    
    //연산, 출력
    cout<< parametricSearch(snack_len, min_len, max_len, m)<<'\n';

    return 0;
}