//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//int N, C;
//vector<pair<int, int>> v;
////map���
////map <int, int> m;
//
//bool comp(pair<int, int> p1, pair<int, int> p2)
//{
//	//�ι�° ���ڸ� �������� �����ϱ�(��������)
//	return p1.second > p2.second;
//	//�ι�° ���ڰ� ���ٸ�
//	if (p1.second == p1.second)
//	{
//		//ó���� ����� ��p1.first
//	}
//	//���� ���� ������ �α�(�������� �ʱ�?)
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
//		if (v.end() == it)//���Ұ� ���ٸ�
//		{
//			v.push_back({ num, 1 });
//
//			//v[find(v.begin(), v.end(), num)-v.begin()].second ++;
//		}
//		else//�ִٸ�
//		{
//			it -> second ++;
//		}
//	}
//
//	//�󵵷� �����ϱ�
//	sort(v.begin(), v.end(), comp);
//
//	//���
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = 0; j < v[i].second; j++)//second�� 2��, 0, 1 �� �ι� ���
//		{
//			cout << v[i].first <<" ";
//		}
//	}
//	return 0;
//}