//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//int N, C;
//vector<pair<int, int>> v;
////map방법
////map <int, int> m;
//
//bool comp(pair<int, int> p1, pair<int, int> p2)
//{
//	//두번째 인자를 기준으로 정렬하기(내림차순)
//	return p1.second > p2.second;
//	//두번째 인자가 같다면
//	if (p1.second == p1.second)
//	{
//		//처리를 해줘야 함p1.first
//	}
//	//먼저 나온 순으로 두기(정렬하지 않기?)
//
//}
//
//
//int main()
//{
//
//	cin >> N>>C;
//	for (int i = 0; i < N; i++)
//	{
//		int num;
//		cin >> num;
//		auto it = find_if(v.begin(), v.end(), [&num] (const pair<int, int>&elem)
//		{
//			return elem.first == num;
//		});
//		if (v.end() == it)//원소가 없다면
//		{
//			v.push_back({ num, 1 });
//
//			//v[find(v.begin(), v.end(), num)-v.begin()].second ++;
//		}
//		else//있다면
//		{
//			it -> second ++;
//		}
//	}
//
//	//빈도로 정렬하기
//	sort(v.begin(), v.end(), comp);
//
//	//출력
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = 0; j < v[i].second; j++)//second가 2면, 0, 1 즉 두번 출력
//		{
//			cout << v[i].first <<" ";
//		}
//	}
//	return 0;
//}