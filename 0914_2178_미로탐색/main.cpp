#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// N x M 크기의 배열로 표현된 미로를 탈출하는 최단경로를 구해라.

int n, m, answer;
int dx[] = { 1, 0 , -1, 0 };
int dy[] = { 0, -1, 0, 1 };
vector<vector<int>> maze;
vector<vector<bool>> visited;
vector<vector<int>> dist;

void BFS(int x = 0, int y = 0)
{
	queue<pair<int, int>> q;

	// 1. 방문 여부 true
	visited[x][y] = true;
	// 2. q 에 push
	q.push({ x, y });
	// 3. 현재 노드까지의 거리 증가
	dist[x][y]++;
	// 4. q 가 빌때까지 반복한다.
	while (!q.empty())
	{
		// a. 큐에 들어 있는 정보 불러오기
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// b. 4 방향 탐색
		for (int i = 0; i < 4; ++i)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || xx >= n || yy < 0 || yy >= m)	continue;
			if (maze[xx][yy] == 1 && visited[xx][yy] == false)
			{
				visited[xx][yy] = true;
				q.push(make_pair(xx, yy));
				dist[xx][yy] = dist[x][y] + 1;
			}
		}
	}
}

int main()
{
	// 1. 입력받기
	cin >> n >> m;
	maze.assign(n, vector<int>(m));
	visited.assign(n, vector<bool>(m, false));
	dist.assign(n, vector<int>(m));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%1d", &maze[i][j]);

	// 2. BFS 를 활용 최소 경로를 계산한다.
	BFS();

	// 3. 결과 출력
	cout << dist[n-1][m-1];
}