//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int main()
//{
//	vector<pair<int, int>> times;
//	//�켱 ���� ť--> �ڵ����� �������� ���� ����
//	// �츮��  ���� ���� ���� �����ٰ� ���ƾ� ��
//	//���� �����ͺ��� top����
//	priority_queue<int, vector<int>, greater<int>> pq;
//	//�� �׳� int�� �ƴϰ� <int, vector<int>, greater<int>> �̷���?
//	int n, begin, end;
//
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> begin >> end;	
//		times.push_back(make_pair(begin, end));
//	}
//
//	//���� ������ �������� ����
//	sort(times.begin(), times.end());
//
//	//������ �ð� push
//	pq.push(times[0].second);
//	for (int i = 1; i < n; i++)
//	{
//		//���� ������ �ð��� ���� ���۽ð����� ũ��
//		if(pq.top() <= times[i].first)
//			pq.pop();//pop�� �Ʒ����� ����
//		pq.push(times[i].second);
//	}
//
//	int answer= pq.size();
//
//	cout << answer;
//	return 0;
//
//}