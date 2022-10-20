#include <iostream>
#include <vector>

using namespace std;

int N, del, root, answer;

vector<vector<int>> tree;	// <노드번호, 자식수>
vector<bool> visited;		// <노드번호>

void SearchNode(int node);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// 1. 입력 받기
	cin >> N;

	tree.assign(N, vector<int>(0));
	visited.assign(N, false);

	for (int i = 0; i < N; ++i)
	{
		int index;
		cin >> index;
		// a. 입력 받은 값이 -1 이라면 root node
		if (index == -1)
		{
			root = i;
			continue;
		}
		// b. 그렇지 않다면 자식을 넣어준다.
		tree[index].push_back(i);
	}
	// c. 삭제할 노드
	cin >> del;

	// 2. 예외처리
	// -> 삭제할 노드가 root node 라면 종료
	if (del == root)
	{
		cout << "0";
		return 0;
	}

	// 3. 트리 탐색
	SearchNode(root);

	// 4. 결과 출력
	cout << answer;
}

void SearchNode(int node)
{
	// 1. 방문 체크
	visited[node] = true;

	// 2. 결과 더하기
	// a. 현재 노드가 리프 노드라면 
	// b. 현재 노드의 자식이 1개 이고, 그 자식이 삭제할 노드라면 현재 노드가 리프 노드가 된다.
	//  ※ b 조건 없으면 오답
	if (tree[node].size() == 0 || tree[node].size() == 1 && tree[node][0] == del)
	{
		++answer;
		return;
	}

	// 3. 노드를 탐색한다.
	for (int i = 0; i < tree[node].size(); ++i)
	{
		// a. 다음 노드 선택
		int next = tree[node][i];
		// b. 다음 노드가 삭제할 노드이거나 방문했다면 continue
		if (next == del || visited[next])	continue;
		// c. 재귀
		SearchNode(next);
	}
}