//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int N;
//
//	cin >> N;
//	//2�� 5 ���� �˻� --> 1~ N���� ��� ���ϱ� : �ð��ʰ�
//	//5 �� ������ ������ 2�� �������� �����Ƿ� 5�� ������ �˻����൵ ��
//	for (int i = 0; i < N; i++)
//	{
//		int num;
//		int twoCount =0,fiveCount=0;
//
//		cin >> num;
//		
//		for (int j = 5; j <= num; j *= 5)
//		{
//			fiveCount += num/j;
//		}
//		cout << fiveCount<<'\n';
//	}
//	return 0;
//}