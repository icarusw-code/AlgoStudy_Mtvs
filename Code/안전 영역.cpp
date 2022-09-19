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

queue<pair<int, int>> q;//�湮���� ��� �����ϴ� ť

//�ð����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

//o���� ũ�� N������ ���� �Ǻ���(���� �������� �ʵ��� �˻�)
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

//�̺κ��� �ܿ� ��
void BFS(int x, int y, int rainHeight)
{
	//�湮�ߴٰ� ǥ��
	visited[x][y] = 1;
	q.push({x, y});//���� ���� ť�� �ֱ�

	while (!q.empty())
	{
		//���� �տ� �ִ� �� = 
		//����ť�� �����ִ� �� �߿��� ������ ���� ������ ��??
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
	//���ũ�� �Է� �ޱ�
	cin>>N;

	//�������� �����
	//���������� �ִ����, �ּ� ���� ���ϱ�
	//�׷��� �� �Ë��� �ִ� �ּ� ������ ������ �� ����
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

	//�� �� �� �ִ� ��� minHeight < K <Maxheight
	for (int k = minHeight; k <= maxHeight; k++)
	{
		//�ʱ�ȭ
		int count=0;
		memset(visited, 0, sizeof(visited));

		//�� ������ ó�� (0,0)���� (N, N) ���� ���鼭 Ȯ��
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				//�湮 ���߰� �� ���̺��� ������
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