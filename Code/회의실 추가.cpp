//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////���Լ�
///*
//bool Compare(const pair<int, int>& a, const pair<int, int>& b)
//{
//	if (a.second == b.second) //second���� ������
//	{
//		return a.first>b.first;//first���� �� ū�� ������
//	}
//	return a.second > b.second; //�� ū���� ������
//}
//*/
//int main()
//{
//	//ȸ�� �ð��� ª�ƾ� �Ѵ�
//	//ȸ�� ���̿� ������ ª�ƾ� �Ѵ�
//	int n, begin, end, minStart;
//	
//	cin >> n;
//	vector<pair<int, int>> times;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> begin >>end;
//		times.push_back(make_pair(end, begin));
//	}
//
//	//���� ������ ���� ������ ����
//	sort(times.begin(), times.end());
//
//	minStart=times[0].first;
//	cout << minStart <<endl;
//	int answer = 1;
//	for (int i = 1; i < n; i++)
//	{
//		if (minStart <= times[i].second)
//		{
//			answer++;
//			minStart=times[i].first;
//
//			cout << times[i].first << " " << times[i].second << endl;
//		}
//	}	
//	cout << answer;
//	return 0;
//}