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
//	//2와 5 개수 검사 --> 1~ N까지 모두 구하기 : 시간초과
//	//5 의 개수가 무조건 2의 개수보다 적으므로 5의 개수만 검사해줘도 됨
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