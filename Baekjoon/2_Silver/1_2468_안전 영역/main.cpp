#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, answer, maxHeight = 0;

vector<vector<int>> height;
vector<vector<bool>> isVisited;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void SolutionByDFS();
void DFS(int x, int y, int flood);
void SolutionByBFS();
void BFS(int x, int y, int flood);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	// 장마철 침수지역을 제외한 안전한 영역의 최대 개수를 출력하고 싶다.
	// 1. 입력받는다.
	cin >> n;

	height.assign(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> height[i][j];
			maxHeight = max(maxHeight, height[i][j]);
		}
	}

	// 2. 결과를 도출한다.
	for (int floodHeight = 0; floodHeight < maxHeight; ++floodHeight)
	{
		int cnt = 0;
		// b. 방문기록 초기화
		isVisited.assign(n, vector<bool>(n));
		// c. DFS 탐색
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				// d. 안전 지역 여부 확인
				// -> 건물의 높이가 침수 높이보다 크고 방문하지 않았다면
				if (height[i][j] > floodHeight && isVisited[i][j] == false)
				{
					// 2-1. DFS 사용
					DFS(i, j, floodHeight);
					// 2-2. BFS 사용
					//BFS(i, j, floodHeight);
					++cnt;
				}
			}
		}
		// e. 카운팅한 변수를 결과와 비교하여 저장
		answer = max(answer, cnt);
	}

	// 3. 결과를 출력한다
	cout << answer;
}

void DFS(int x, int y, int flood)
{
	// 1. 방문 여부 true
	isVisited[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		// 2. 탐색 좌표 설정
		int xx = x + dx[i];
		int yy = y + dy[i];

		// 3. index 범위 거르기
		if (xx < 0 || xx >= n || yy < 0 || yy >= n)	continue;
		// 4. 안전 지역 확인
		// -> 건물의 높이가 침수 높이보다 크고 방문하지 않았다면
		if (height[xx][yy] > flood && isVisited[xx][yy] == false)
		{
			// 5. 탐색 실행
			DFS(xx, yy, flood);
		}
	}
}

void BFS(int x, int y, int flood)
{
	queue<pair<int, int>> q;

	// 1. 방문 여부 true
	isVisited[x][y] = true;
	// 2. q 에 push
	q.push({ x, y });
	// 3. q 가 빌때까지 반복한다.
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

			if (xx < 0 || xx >= n || yy < 0 || yy >= n)	continue;
			if (height[xx][yy] > flood && isVisited[xx][yy] == false)
			{
				isVisited[xx][yy] = true;
				q.push(make_pair(xx, yy));
			}
		}
	}
}