#include <iostream>
#include <vector>

using namespace std;

int N, M;
int maxCnt, curCnt;

vector<vector<int>> com;
vector<int> visited;
vector<int> answer;

void Input()
{
	cin >> N >> M;

	com.assign(N + 1, vector<int>(0));

	for (int i = 0; i < M; ++i)
	{
		// 1 -> 3 -> 4
		// 2 ->	  -> 5
		int top, bottom;
		cin >> bottom >> top;
		com[top].push_back(bottom);
	}

	answer.push_back(1);
}

void SearchNode(int node)
{
	// 1. 방문 확인
	visited[node] = true;

	// 2. 노드 탐색
	for (int i = 0; i < com[node].size(); ++i)
	{
		// a. 다음 노드 선정
		int next = com[node][i];
		if (visited[next])	continue;
		// b. 결과 누적 및 재탐색
		++curCnt;
		SearchNode(next);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// 1. 입력받기
	Input();

	// 2. 1번 부터 탐색
	for (int i = 1; i <= N; ++i)
	{
		// a. 방문 초기화
		visited.assign(N + 1, false);
		// b. 해킹 가능한 수 초기화
		curCnt = 0;
		// c. 탐색
		SearchNode(i);
		// d. 탐색한 결과가 정답보다 크거나 같으면 push
		if (maxCnt <= curCnt)
		{
			//	단, 정답보다 크다면 vector clear
			if(maxCnt < curCnt)
			{
				maxCnt = curCnt;
				answer.clear();
			}
			answer.push_back(i);
		}
	}

	// 3. 결과 출력
	for (vector<int>::iterator it = answer.begin(); it != answer.end(); ++it)
		cout << *it << " ";
}