#include <iostream>
#include <vector>
#include<queue>
#include<memory.h>

using namespace std;

int N;
int safeArea=1;
int height[101][101];
int visited[101][101]={0};
int minHeight= -1;
int maxHeight= 101;

queue<pair<int, int>> q;//방문중인 노드 저장하는 큐

//시계방향
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

//o보다 크고 N이하인 범위 판별용(범위 오버되지 않도록 검사)
int safe(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//이부분은 외울 것
void BFS(int x, int y, int rainHeight)
{
	//방문했다고 표시
	visited[x][y] = 1;
	q.push({x, y});//현재 지점 큐에 넣기

	while (!q.empty())
	{
		//가장 앞에 있는 것 = 
		//현재큐에 남아있는 것 중에서 들어온지 가장 오래된 것??
		x = q.front().first;
		y= q.front().second;
		q.pop();
		for (int i = 0; i< 4; i++)
		{
			int xpos=x + dx[i];
			int ypos = y+dy[i];

			if (safe(xpos, ypos) == 1 && visited[xpos][ypos] == 0 && height[xpos][ypos] > rainHeight)
			{
				visited[xpos][ypos]=1;
				q.push({xpos, ypos});
			}
		}
	}
}
int main()
{
	//행렬크기 입력 받기
	cin>>N;

	//높이지도 만들기
	//높이지도의 최대높이, 최소 높이 구하기
	//그러면 비가 올떄의 최대 최소 범위를 지정할 수 있음
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> height[i][j];
			if (maxHeight < height[i][j])
			{
				maxHeight = height[i][j];
			}
			if (minHeight > height[i][j])
			{
				minHeight = height[i][j];
			}
		}
	}

	//비가 올 수 있는 경우 minHeight < K <Maxheight
	for (int k = minHeight; k <= maxHeight; k++)
	{
		//초기화
		int count=0;
		memset(visited, 0, sizeof(visited));

		//비 지도를 처음 (0,0)부터 (N, N) 까지 돌면서 확인
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				//방문 안했고 비 높이보다 높으면
				if (visited[i][j] == 0 && height[i][j] > k)
				{
					BFS(i, j, k);
					count ++;
				}
			}
		}
		if(count > safeArea)
			safeArea=count;
	}
	cout << safeArea;

	return 0;
}