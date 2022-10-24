#include <iostream>
#include <vector>


using namespace std;


int maxPartial(vector<int>& arr,int n, int limit) {

    int left = 0, right = 0;
    int ans = 1;

    int number[200001] = { 0, };
   
    while (right < n) {

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
