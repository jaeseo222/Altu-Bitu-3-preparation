#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * 큰 값과 작은 값을 곱해 최솟값을 구할 수 있음
 * 각 배열을 오름차순, 내림차순으로 정렬하여 곱 구하기
*/
int main()
{
    int n, s = 0;

    // 입력
    cin >> n;
    vector<int> a(n, 0), b(n, 0);
    for (int i = 0; i < n; i++) { 
        cin >> a[i]; // A 입력 받기
    }
    for (int i = 0; i < n; i++) { 
        cin >> b[i]; // B 입력 받기
    }
    sort(a.begin(), a.end()); // A 오름차순 정렬
    sort(b.begin(), b.end(), greater<>()); // B 내림차순 정렬

    // 연산
    for (int i = 0; i < n; i++) { 
        s += a[i] * b[i]; // 배열 A, B의 각 원소의 곱 더하기
    }
    // 출력
    cout << s;
}
