//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//int main()
//{
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		bool flag=true;
//		stack<char> s;
//		string ps;
//		cin >> ps;
//		for (int j = 0; j < ps.length(); j++)
//		{
//			if(ps[j] =='(')
//				s.push(ps[j]);
//			// )��ȣ�� ���Դµ� pop�� �� ������
//			else
//			{
//				if (s.empty())
//				{
//					flag = false;
//					break;
//				}
//				s.pop();
//			}
//		}
//		if(flag && !s.empty())
//		{
//			flag=false;
//		}
//
//		if(flag)
//			cout << "YES"<<endl;
//		else
//			cout << "NO"<<endl;
//	}
//
//	return 0;
//
//}