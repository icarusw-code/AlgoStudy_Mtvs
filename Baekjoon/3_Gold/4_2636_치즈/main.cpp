#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int H, W;					// 입력
int hour, cnt = -1;			// 결과
int dx[] = { 1, 0, -1, 0 };	// 탐색 Index
int dy[] = { 0, 1, 0, -1 };
bool isLast = false;

vector<vector<int>> cheese;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

void CheckCheese();
void CountCheese();
void BFS();

int main()
{
	// 1. 입력 받기
	cin >> H >> W;

	cheese.assign(H, vector<int>(W, 0));

	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			cin >> cheese[i][j];

	// 2. 결과 도출
	while (true)
	{
		// a. 남은 치즈 검사
		CheckCheese();
		if (isLast)	break;
		// b. 치즈 개수 세기
		CountCheese();
		// c. 치즈 녹이기
		BFS();
	}
	// 3. 결과 출력
	cout << hour << '\n' << cnt << '\n';
}

// 남은 치즈가 있는지 검사하는 함수
void CheckCheese()
{
	// a. 치즈가 남았다면 종료
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			if (cheese[i][j] == 1)
				return;

	// b. 치즈가 남지 않았다면 마지막 true
	isLast = true;
}

// 남은 치즈의 개수를 세는 함수
void CountCheese()
{
	// a. 시간 흐름
	++hour;

	// b. 치즈 개수 계산
	cnt = 0;
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			if (cheese[i][j] == 1)
				++cnt;
}

void BFS()
{
	// 1. 방문 초기화
	visited.assign(H, vector<bool>(W, false));
	// 2. 첫 노드 탐색
	q.push({ 0, 0 });
	visited[0][0] = true;
	// 3. 반복
	while (!q.empty())
	{
		// a. 탐색위치 설정
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			// b. 탐색방향 설정
			int xx = x + dx[i];
			int yy = y + dy[i];

			// c. 조건 거르기
			if (xx < 0 || xx >= H || yy < 0 || yy >= W || visited[xx][yy] == true)	continue;
			
			// d. 공기(0)라면 push
			if (cheese[xx][yy] == 0)	q.push({ xx, yy });
			
			// e. 치즈라면 녹인다
			else if (cheese[xx][yy] == 1)	cheese[xx][yy] = 0;
			
			visited[xx][yy] = true;
		}
	}
}
