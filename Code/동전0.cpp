//#include <iostream>
//#include <stack>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	int moneySum;
//	int answer=0;
//	stack<int> moneys; 
//
//	cin>> n >> moneySum;
//
//	for (int i = 0; i < n; ++i)
//	{
//		int tempValue;
//		cin >> tempValue;
//		moneys.push(tempValue);
//	}
//
//	while(!moneys.empty())// for each처럼 쓸 수 있음
//	{
//		while(moneySum >= moneys.top())//나누기로(몫)
//		{
//			moneySum -= moneys.top();
//			answer++;
//		}
//		moneys.pop();
//	}
//	cout<< answer;
//
//
//}