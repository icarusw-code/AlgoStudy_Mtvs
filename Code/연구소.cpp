//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int Y, X;
//int dx[4]={0, 1, 0, -1};
//int dy[4]={1, 0, -1, 0};
//int answer;
//
//bool isSafe(int x, int y)
//{
//	if(x>=0 && x<X && y>=0 && y<Y)
//		return true;
//	return false;
//}
//void bfs(vector<vector<int>> v)
//{
//	queue<pair<int, int>> q;
//	int safeCount=0;
//	
//	//��� map�� ���鼭 2�� �κ� ť�� �ֱ�
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = 0; j < v[i].size(); j++)
//		{
//			if (v[i][j] == 2)
//			{
//				q.push({i, j});
//			}
//		}
//	}
//
//	//�׷��� ť���� ����ִ� ��ǥ�鿡�� �� �����鼭 ã��
//	while (!q.empty())
//	{
//		//���� ��ǥ �ޱ�(��״� �̹� 2)
//		int x=q.front().first;
//		int y=q.front().second;
//
//		//ť���� ���ֱ�
//		q.pop();
//
//		//�����¿� Ž��
//		for (int i = 0; i < 4; i++)
//		{
//			int xPos = x + dx[i];
//			int yPos = y + dy[i];
//
//			if (isSafe(xPos, yPos) && v[xPos][yPos] == 0)
//			{
//				v[xPos][yPos]=2;
//				q.push({xPos, yPos});
//			}
//		}
//	}
//
//	//��ü���� ������ ������ ����� ���ϱ�
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = 0; j < v[i].size(); j++)
//		{
//			if (v[i][j] == 0)
//			{
//				safeCount++;
//			}
//		}
//	}
//	answer = max(safeCount, answer);
//}
//
////0�� �ڸ��� 1 3�� �ִ� ��� ã�� ����(DFS��)
////�̰Ŵ� ��Ʈ����ŷ���� Ǯ �� ����? next_permutation
//void dfs(vector<vector<int>> v, int x, int y, int cnt)
//{
//	//cnt�� ��ġ�� ����-1
//	v[x][y]=1;
//	if (cnt == 0)
//	{
//		//���� ����� Ž���ϱ�
//		bfs(v);
//		return;
//	}
//	for (int i = x; i < v.size(); i++)
//	{
//		//j�� �� y�� �ƴϰ� 0����
//		for (int j = 0; j < v[x].size(); j++)
//		{
//			if(v[i][j]==0)
//				dfs(v, i, j, cnt-1);
//		}
//	}
//}
//int main()
//{
//	//�Է�
//	cin >> X >> Y;
//	//�ʱ�ȭ
//	vector<vector<int>> v(X, vector<int>(Y));
//	for (int i = 0; i < X; i++)
//	{
//		for (int j = 0; j < Y; j++)
//		{
//			cin >> v[i][j];
//		}
//	}
//
//	//Ž��
//	//�ñ��� �� --> DFS���� ���� ������ ������ v �ٽ� �ʱ�ȭ �����൵ ��?
//	for (int i = 0; i < X; i++)
//	{
//		for (int j = 0; j < Y; j++)
//		{
//			if (v[i][j] == 0)
//			{
//				dfs(v, i, j, 2);
//			}
//		}
//	}
//
//	cout << answer;
//	
//	return 0;
//}