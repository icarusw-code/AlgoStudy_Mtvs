//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int n, m;
//int map[101][101];//�̷� �迭
//int visited[101][101];
//int dist[101][101];
//
//int main()
//{
//	
//	cin >> n >> m;
//
//	//���(�̷�) �Է� �ޱ�
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
//	//�湮 ������ ������ 1�� �����ֱ�
//	dist[x][y] ++;
//	//map[x][y]������
//	//�����¿� �� �� �ִ� ������ �Ǻ��ϱ�
//	//a, b
//	map[x-1][y]
//	map[x+1][y]
//	map[x][y+1]
//	map[x][y-1]
//
//	//����map����
//	if (map[a][b] ==1 && visited[a][b] == 0 &&x>0 &&y>0)
//	//���� �ִٸ�, �湮���� �ʾҴٸ�, ���� 0���϶��
//	{
//		visited[a][b]=1;
//		x=a;
//		y=b;
//		BFS(x, y);
//	}
//}