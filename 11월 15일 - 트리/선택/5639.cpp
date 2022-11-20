#include<iostream>
#include<vector>

using namespace std;

/*
전위 순회로 입력된 노드 값을 후위 순위로 출력
전위 순회 (root->left->right)가 재귀적으로 반복
후위 순회 (left->right->root)이 재귀적으로 반복
 temp가 기준
 temp를 기준으로 작은 값이 있으면 해당 원소를 기준으로 왼쪽,오른쪽 나누어 다시 postOrder진행
*/

void postOrder(int left, int right, vector<int> &tree) {
	if (left > right) {
		return;
	}
	int temp = left + 1;

	for (int i = left + 1; i < right + 1; i++) {
		if (tree[left] < tree[i]) {
			temp = i;
			break;
		}
	}
	postOrder(left + 1, temp-1,tree);
	postOrder(temp, right, tree);
	
	cout << tree[left] << '\n';
}

int main() {
	int input;
	vector<int> tree;
	//tree에 원소 입력(전위순회)
	while (cin >> input) {
		tree.push_back(input);
	}
	postOrder(0, tree.size()-1,tree);
}
