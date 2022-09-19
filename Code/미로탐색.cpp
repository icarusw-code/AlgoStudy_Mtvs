//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int n, m;
//int map[101][101];//미로 배열
//int visited[101][101];
//int dist[101][101];
//
//int main()
//{
//	
//	cin >> n >> m;
//
//	//행렬(미로) 입력 받기
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			int temp;
//			cin >> temp;
//			map[i][j]=temp;
//		}
//	}
//	BFS(0, 0);
//
//	cout << dist[n][m];
//	return 0;
//}
//
//void BFS(int x, int y)
//{
//
//	if(x==n && y== m) return;
//	//방문 가능할 때마다 1씩 더해주기
//	dist[x][y] ++;
//	//map[x][y]시작점
//	//상하좌우 갈 수 있는 곳인지 판별하기
//	//a, b
//	map[x-1][y]
//	map[x+1][y]
//	map[x][y+1]
//	map[x][y-1]
//
//	//위의map값이
//	if (map[a][b] ==1 && visited[a][b] == 0 &&x>0 &&y>0)
//	//갈수 있다면, 방문하지 않았다면, 각각 0이하라면
//	{
//		visited[a][b]=1;
//		x=a;
//		y=b;
//		BFS(x, y);
//	}
//}