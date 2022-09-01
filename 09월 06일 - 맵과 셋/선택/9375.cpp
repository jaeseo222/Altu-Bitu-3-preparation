#include <iostream>
#include <map>

using namespace std;

/**
 * 의상의 종류만 알면 된다.
 */

int main() {
    int T, n;
    string clothes, kind;

    cin >> T;
    while (T--) {
        map<string, int> m;

        //입력
        cin >> n;
        while (n--) {
            cin >> clothes >> kind;
            m[kind]++;
        }

        
        int result = 1;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            result *= iter->second + 1; 
        }

        //출력
        cout << result - 1 << '\n';  //알몸인 경우 제외
    }
}