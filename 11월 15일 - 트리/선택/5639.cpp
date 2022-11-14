#include<iostream>
#include<vector>

using namespace std;

/*
전위 순회로 입력된 노드 값을 후위 순위로 출력
전위 순회 (자기 자신->left->right)가 재귀적으로 반복
후위 순회 (left->right->자기 자신)이 재귀적으로 반복
 temp가 기준
 temp를 기준으로 작은 값이 있으면 해당 원소를 기준으로 왼쪽,오른쪽 나누어 다시 postOrder진행
*/

void postOrder(int start, int end, vector<int> &tree) {
	if (start > end) {
		return;
	}
	int temp = start + 1;

	for (int i = start + 1; i < end + 1; i++) {
		if (tree[start] < tree[i]) {
			temp = i;
			break;
		}
	}
	postOrder(start + 1, temp-1,tree);
	postOrder(temp, end, tree);
	
	cout << tree[start] << '\n';
}

int main() {
	int input;
	vector<int> tree;
	//tree에 원소 입력(전위순회)
	while (cin >> input) {
		tree.push_back(input);
	}
	//cout << tree.size()<<"\n";
	postOrder(0, tree.size()-1,tree);
}
