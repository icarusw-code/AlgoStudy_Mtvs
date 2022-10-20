#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, answer;
int wallCnt;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

vector<vector<int>> origin;
vector<vector<int>> virus;
queue<pair<int, int>> q;

void BFS();
void BuildWall();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// 1. 입력받기
	cin >> N >> M;

	origin.assign(N, vector<int>(M, 0));
	virus.assign(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> origin[i][j];

	// 2. 벽 세우기
	BuildWall();

	// 3. 결과 출력
	cout << answer;
}

void BFS()
{
	// 1. virus 심기
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (origin[i][j] == 2)	q.push({ i, j });

	// 2. BFS 탐색 (virus 퍼트리기)
	while (!q.empty())
	{
		// a. 좌표 설정
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			// b. 범위 거르기
			if (xx < 0 || xx >= N || yy < 0 || yy >= M)	continue;
			// c. 오염되지 않았다면
			if (virus[xx][yy] == 0)
			{
				// d. 오염시킨다.
				q.push({ xx, yy });
				virus[xx][yy] = 2;
			}
		}
	}

	// 3. 결과 계산
	int cnt = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (virus[i][j] == 0)	++cnt;

	answer = max(answer, cnt);
}

void BuildWall()
{
	// 1. 벽이 모두 설치 되었다면
	if (wallCnt > 2)
	{
		// 2. 바이러스 퍼뜨리기
		// -> 벽을 세운 맵(origin)을 시뮬레이션 할 맵(virus)에 복사
		copy(origin.begin(), origin.end(), virus.begin());
		BFS();
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			// a. 벽을 세울 수 있다면
			if (origin[i][j] == 0)
			{
				// b. 벽을 세우고
				origin[i][j] = 1;
				++wallCnt;
				// c. 재귀를 통해 3 개의 벽 설치
				BuildWall();
				--wallCnt;
				origin[i][j] = 0;
			}
		}
	}
}