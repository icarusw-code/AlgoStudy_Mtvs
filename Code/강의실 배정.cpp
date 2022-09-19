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
//	//우선 순위 큐--> 자동으로 내림차순 정렬 해줌
//	// 우리는  값이 작은 것을 위에다가 놓아야 함
//	//값이 높은것부터 top으로
//	priority_queue<int, vector<int>, greater<int>> pq;
//	//왜 그냥 int가 아니고 <int, vector<int>, greater<int>> 이렇게?
//	int n, begin, end;
//
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> begin >> end;	
//		times.push_back(make_pair(begin, end));
//	}
//
//	//시작 시점을 기준으로 정렬
//	sort(times.begin(), times.end());
//
//	//끝나는 시간 push
//	pq.push(times[0].second);
//	for (int i = 1; i < n; i++)
//	{
//		//만약 끝나는 시간이 다음 시작시간보다 크면
//		if(pq.top() <= times[i].first)
//			pq.pop();//pop은 아래것이 빠짐
//		pq.push(times[i].second);
//	}
//
//	int answer= pq.size();
//
//	cout << answer;
//	return 0;
//
//}