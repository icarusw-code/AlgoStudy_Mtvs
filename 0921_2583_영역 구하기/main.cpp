// M x N 크기의 모눈종이에 눈금에 맞추어 K 개의 직사각형을 그린다.
// 직사각형의 영역을 제외하고 남은 영역들의 개수와 각 영역의 넓이를 구해라. ( 출력 )
//  -> 각 영역의 넓이를 저장할 변수가 필요하다!
//  -> 남은 영역의 넓이를 저장할 남은 영역의 개수만큼의 vector 가 필요하다!
//  -> vector 의 크기 : 남은 영역의 개수, 각 vector 의 값 : 각 영역의 넓이
// 
// M, N, K 가 주어진다.
// K 만큼의 왼쪽 아래 꼭지점 (x1, y1) 과 오른쪽 위 꼭지점 (x2, y2) 가 주어진다.
//  -> 꼭지점들을 저장할 변수가 필요하다!
// 
// 모눈종이의 왼쪽 아래 꼭지점의 좌표는 (0, 0), 오른쪽 위 꼭지점의 좌표는 (N, M)
//  -> 왼쪽 위 꼭지점의 좌표를 (0, 0), 오른쪽 아래 꼭지점의 좌표를 (N, M) 으로 변환시켜보자!
// 
// K 개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.
//  -> 반드시 탐색은 이루어진다.

/*
< 입력 예시 >				< 출력 예시 >
5 7 3						3
0 2 4 4						1 7 13
1 1 2 5
4 0 6 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K, cnt;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

vector<vector<int>> graph;
vector<int> area;

void DrawGraph();

void DFS(int x, int y)
{
	// 1. 넓이 더하기
	++cnt;
	// 2. 방문하면 값 변화
	graph[x][y] = 1;
	// 3. 4 방향 탐색
	for (int i = 0; i < 4; ++i)
	{
		// a. 탐색 좌표 설정
		int xx = x + dx[i];
		int yy = y + dy[i];
		// b. 탐색 조건 거르기
		// -> 배열 범위 벗어난 경우, 이미 방문한 경우
		if (xx < 0 || xx >= M || yy < 0 || yy >= N || graph[xx][yy] == 1) continue;
		DFS(xx, yy);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	// 1. 입력 받는다.
	cin >> M >> N >> K;

	graph.assign(M, vector<int>(N, 0));

	for (int k = 0; k < K; ++k)
	{
		// a. (x1, y1), (x2, y2) 좌표 입력 받기
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		// b. 해당 범위만큼 값 변경
		for (int i = x1; i < x2; ++i)
			for (int j = y1; j < y2; ++j)
				graph[i][j] = 1;
	}

	//DrawGraph();

	// 2. DFS 로 결과를 도출한다.
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (graph[i][j] == 0)
			{
				// a. 각 영역의 넓이를 계산하기 위해 초기화
				cnt = 0;
				DFS(i, j);
				// b. DFS 로 계산한 cnt 값을 저장
				area.push_back(cnt);
			}
		}
	}

	// 3. 결과를 출력한다.
	// a. 오름차순 출력을 위한 정렬
	sort(area.begin(), area.end());
	cout << area.size() << '\n';
	for (vector<int>::iterator iter = area.begin(); iter != area.end(); ++iter)
		cout << *iter << ' ';
}

void DrawGraph()
{
	// 그래프 표시
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << graph[i][j];
		}
		cout << endl;
	}
}