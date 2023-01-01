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
//	//모든 map을 돌면서 2인 부분 큐에 넣기
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
//	//그러면 큐에서 들어있는 좌표들에서 쭉 퍼지면서 찾음
//	while (!q.empty())
//	{
//		//기존 좌표 받기(얘네는 이미 2)
//		int x=q.front().first;
//		int y=q.front().second;
//
//		//큐에서 빼주기
//		q.pop();
//
//		//상하좌우 탐색
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
//	//전체에서 안전한 영역이 몇개인지 구하기
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
////0인 자리에 1 3개 넣는 방법 찾기 조합(DFS로)
////이거는 비트마스킹으로 풀 수 없음? next_permutation
//void dfs(vector<vector<int>> v, int x, int y, int cnt)
//{
//	//cnt는 설치할 개수-1
//	v[x][y]=1;
//	if (cnt == 0)
//	{
//		//영역 몇개인지 탐색하기
//		bfs(v);
//		return;
//	}
//	for (int i = x; i < v.size(); i++)
//	{
//		//j는 왜 y가 아니고 0이지
//		for (int j = 0; j < v[x].size(); j++)
//		{
//			if(v[i][j]==0)
//				dfs(v, i, j, cnt-1);
//		}
//	}
//}
//int main()
//{
//	//입력
//	cin >> X >> Y;
//	//초기화
//	vector<vector<int>> v(X, vector<int>(Y));
//	for (int i = 0; i < X; i++)
//	{
//		for (int j = 0; j < Y; j++)
//		{
//			cin >> v[i][j];
//		}
//	}
//
//	//탐색
//	//궁금한 점 --> DFS돌고 나서 리턴할 때마다 v 다시 초기화 안해줘도 됨?
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