#include <iostream>
#include <deque>
#include <vector>

using namespace std;
typedef vector<vector<int>> matrix;

int countTrees(int n, vector<deque<int>>& trees) {
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			answer += trees[i * 10 + j].size();
		}
	}
	return answer;
}

void reproduceTree(int n, int x, int y, vector<deque<int>>& trees)
{
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if ((i == x) && (j == y)) {
				continue;
			}
			if (i >= 0 && j >= 0 && i < n && j < n)
			{
				trees[i * 10 + j].push_front(1);
			}
		}
	}
}
void solution(int n, vector<deque<int>>& trees, matrix& food, matrix& A)
{
	vector<pair<int, int>> breeding_tree;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i < n; j++)
		{
			int leftover = 0;
			deque<int> dq;
			for (auto age : trees[i * 10 + j])
			{
				if (food[i][j] < age) { //양분을 먹을 수 없다
					leftover += age / 2;
					continue;
				}
				food[i][j] -= age;
				dq.push_back(age + 1); //나이를 1 증가시킨다
				if ((age + 1) % 5 == 0)// 번식 가능하다
				{
					breeding_tree.push_back({ i, j });
				}
			}
			trees[i * 10 + j] = dq;
			food[i][j] += (A[i][j] + leftover);
		}
	}
	for (auto [i, j] : breeding_tree)
	{
		reproduceTree(n, i, j, trees);
	}
}
/**16235 나무 재테크
 * [문제 설명] - 단순 구현 문제
 * 봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
 *    각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음
 * 여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
 * 가을: 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김
 * 겨울: 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가
 *
 * K년이 지난 후 상도의 땅에 살아있는 나무의 개수
 *
 * [문제 풀이]
 * A : 로봇(S2D2)가 겨울에 주는 양분의 양
 * food : 땅의 양분
 * breeding_tree: 나이가 5의 배수인 트리 (번식할 트리)
 * tree: 땅에 심은 나무 나이, 행, 열 정보
 * -> deque 컨테이너를 활용해 번식한 나무를 앞에 넣어주면 입력 후에만 정렬해서 사용 가능
 *
 * 문제의 설명대로 계절별 연산을 진행
 */
int main()
{
	int n, m, k;
	matrix A(n, vector<int>(n));
	matrix food(n, vector<int>(n, 5));
	matrix arr;
	vector<deque<int>> trees(n * 10 + n);
	//입력
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		trees[x * 10 + y].push_front(z);
	}
	while (k--) {
		solution(n, trees, food, A);
	}
	cout << countTrees(n, trees);
	return 0;
}
