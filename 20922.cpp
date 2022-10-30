#include <iostream>
#include <vector>


using namespace std;


int maxPartial(vector<int>& arr,int n, int limit) {

    int left = 0, right = 0;
    int ans = 1;

    vector<int> number(100001,0); // 등장 횟수 체크
   
    while (left<=right && right < n) {

        if (number[arr[right]] <limit) {

            number[arr[right]]++;
            right++;         
            ans = max(ans, right - left);
        }
        else {
      
            number[arr[left]]--;
            left++;
        }
     
    }

    return ans;
}
/**
 * 1. 최장 연속 부분 수열의 '길이'를 구해야 함 -> 구간 내의 모든 원소를 고려하기 때문에 한쪽에서 시작하는 투 포인터
 * 2. 각 원소의 최댓값이 100,000이기 때문에 배열로 등장 횟수 체크할 수 있음
 * 3. right를 옮기고 바로 원소를 추가했던 기존 방법과 달리, 일단 포인터만 옮겨놓고 원소를 추가해도 되는지 확인
 */

int main() {

    int n, k;

    //입력
    cin >> n >> k;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
       

    cout << maxPartial(arr,n, k); 

}
