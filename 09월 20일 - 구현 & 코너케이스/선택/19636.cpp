#include <iostream>
#include <cmath>

using namespace std;

/**
 * [요요 시뮬레이션] - 단순 구현 문제
 * 다이어트 기간 = d
 * --다이어트 전--
 * 체중 (W0) = before_weight
 * 일일 에너지 섭취량, 일일 기초 대사량 (I0) = before_energy
 * 
 * --다이어트 기간--
 * 일일 에너지 섭취량 (I) = energy_in
 * 일일 활동 대사량 (A) = a
 * 일일 기초 대사량 = b
 * 일일 에너지 소비량 = energy_out
 * 기초 대사량 변화 역치 = t
 * 
 * energy_out = a + b
 * 체중 (weight) += (energy_in - energy_out)
 * if (energy_in - energy_out > t) { b += [ (energy_in - energy_out)/2] }
 *  -> !주의! 이때 일일 기초 대사량에서 더해지는 값이 Floor 함수 적용이므로 음수일 때 값처리 주의해야 함
 */

 typedef pair<int, int> ci;

 //기초대사량 변화하는 경우 처리 함수
ci diet(int d, int before_weight, int energy_in, int a, int before_energy, int t) {
    int b = before_energy;
    int weight = before_weight;
    while (d--) {
        int energy_out = b + a;
        weight += (energy_in - energy_out);

        if (abs(energy_in - energy_out) > t) { //기초대사량 변화
            b += floor((double)(energy_in - energy_out) / 2); //c++에서 음수를 나누면 소수점은 그냥 버려지므로 내림함수 적용
        }
        if (weight <= 0 || b <= 0) {
            return ci(0, 0);
        }
    }
    return ci(weight, b);
}

int main() {
    int before_weight, before_energy, t, d, energy_in, a;

    //입력
    cin >> before_weight >> before_energy >> t;
    cin >> d >> energy_in >> a;

    //일일 기초 대사량의 변화를 고려하지 않는 경우
    int weight = before_weight + (energy_in - (before_energy + a)) * d;
    if (weight <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        cout << weight << ' ' << before_energy << '\n';
    }

    //일일 기초 대사량의 변화를 고려하는 경우
    ci result = diet(d, before_weight, energy_in, a, before_energy, t);
    if (!result.first || !result.second) {
        cout << "Danger Diet\n";
    }
    else {
        string ans = "NO";
        if (before_energy - result.second > 0) {
            ans = "YOYO";
        }
        cout << result.first << ' ' << result.second << ' ' << ans << '\n';
    }
    return 0;
}