//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////비교함수
///*
//bool Compare(const pair<int, int>& a, const pair<int, int>& b)
//{
//	if (a.second == b.second) //second값이 같으면
//	{
//		return a.first>b.first;//first값이 더 큰게 앞으로
//	}
//	return a.second > b.second; //더 큰값이 앞으로
//}
//*/
//int main()
//{
//	//회의 시간이 짧아야 한다
//	//회의 사이에 공백이 짧아야 한다
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
//	//종료 시점을 기준 내림차 정렬
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