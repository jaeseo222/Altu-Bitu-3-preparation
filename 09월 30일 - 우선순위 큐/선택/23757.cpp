#include <iostream>
#include <queue>
using namespace std;

/*
* 아이들은 선물이 가장 많이 담겨있는 상자에서 선물을 가져감
* 선물의 개수가 많을수록 상자의 우선순위가 높다...!
* 실망하는 조건 -> 상자에 원하는 개수보다 적게 선물이 들어있는...!
* 
* Hint 아이들이 선택한 상자는 어떤 특징이 있나요?
*/

int main() {
	int n, m, tmp, child_want, max;
	priority_queue<int> max_heap;
	int flag = 1;
	
	cin >> n >> m;
	
	//우선순위큐에 선물 삽입
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		max_heap.push(tmp);
	}

	//아이들이 원하는 개수를 입력받고 우선순위가 높은 상자에 그 개수보다 적게 선물이 들어있다면 flag를 0으로
	//우선순위가 높은 상자 pop해서 아이가 가져갈 개수 빼고 다시 큐에 삽입 -> 상자의 우선순위 변경
	for (int i = 0; i < m; i++) {

		cin >> child_want;
		if (max_heap.top() < child_want) {
			flag= 0;
			break;
		}

		max = max_heap.top();
		max_heap.pop();
		max_heap.push(max - child_want);

	}

	cout << flag;

	return 0;
}
