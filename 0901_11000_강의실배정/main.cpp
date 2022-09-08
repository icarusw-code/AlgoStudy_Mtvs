#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// 모든 수업 진행을 가능하도록 하는 강의실의 최솟값을 출력하고 싶다.
// 필요속성 : 강의 수, 각 강의의 시작시간 및 종료시간
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// 1. 입력받는다.
	int n;
	cin >> n;
	
	vector<pair<int, int>> lecture(n);
	for (int i = 0; i < n; ++i)	cin >> lecture[i].first >> lecture[i].second;
	
	priority_queue<int, vector<int>, greater<int>> room;
	// 2. 종료 시간을 기점으로 우선순위 큐를 활용하여 강의실의 개수를 구한다.
	// a. 강의 시간을 정렬한다.
	sort(lecture.begin(), lecture.end());
	// b. 첫 번째 강의의 종료시간을 push
	room.push(lecture[0].second);
	for (int i = 1; i < n; ++i)
	{
		// c. 다음 강의의 시작 시간이 진행중인 강의의 종료 시간보다 작으면 push
		if (lecture[i].first < room.top())
		{
			room.push(lecture[i].second);
		}
		// d. 그렇지 않다면 pop
		//  -> 다음 강의의 시작 시간이 진행중인 강의의 종료 시간보다 크거나 같아서 즉시 수업이 가능한 상태라면
		//  -> 큐를 한 칸 비우고 다음 강의의 종료 시간을 push
		else
		{
			room.pop();
			room.push(lecture[i].second);
		}
	}

	// 3. 결과를 출력한다.
	cout << room.size();
}