// M x N 크기의 창고에 토마토를 저장한다.
// 익은 토마토는 1, 안 익은 토마토는 0, 토마토가 없을 땐 -1
// 보관 후 하루가 지나면 익은 토마토에 인접한 안 익은 토마토가 익는다.
// 며칠이 지나면 토마토들이 모두 익는지 최소 일수를 출력
// 단, 토마토가 모두 익어있는 상태면 0 을 출력, 토마토가 모두 익지 못하는 경우라면 -1 을 출력

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N, answer;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

vector<vector<int>> tomato;
queue<pair<int, int>> q;

void BFS()
{
	// a. 큐가 비었을 때 까지 반복
	while (!q.empty())
	{
		// b. 큐에 담긴 정보를 가져오고 pop
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// c. 4 방향 탐색을 시작
		for (int i = 0; i < 4; ++i)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			// d. 조건 거르기
			// -> 배열 범위 벗어난 경우
			if (xx < 0 || xx >= N || yy < 0 || yy >= M)	continue;
			// e. 저장된 값이 0 이면 값을 1 증가 시키고 큐에 push
			// -> 값을 증가 시키는 이유 : 최종 결과를 도출하기 위함
			if (tomato[xx][yy] == 0)
			{
				tomato[xx][yy] = tomato[x][y] + 1;
				q.push({ xx, yy });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// 1. 입력을 받는다.
	cin >> M >> N;

	tomato.assign(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> tomato[i][j];
			// a. 입력 받을 때 1인 값을 바로바로 큐에 push
			if (tomato[i][j] == 1)	q.push({ i, j });

		}
	}

	// 2. BFS 로 계산한다.
	BFS();

	// 3. 저장된 값으로 결과를 도출한다.
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			// a. 방문 좌표가 0 인 곳이 있다면 -1 을 출력하고 프로그램 종료
			if (tomato[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			// b. 가장 큰 값을 결과에 저장
			answer = max(answer, tomato[i][j]);
		}
	}
	// 4. 결과를 출력한다.
	// -> -1 을 해주는 이유 : 초기 값이 1로 시작하기 때문에
	cout << answer - 1;
}