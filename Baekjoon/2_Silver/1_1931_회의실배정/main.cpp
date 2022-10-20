#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair <int, int> P;

// second 기준으로 정렬하는 bool 함수
bool compare(P a, P b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	// 회의실 사용표를 만들어 사용할 수 있는 최대 회의의 개수를 출력하고싶다.
	// 필요속성 : 회의의 수, 각 회의별 시작시간과 끝나는 시간, 시간을 비교할 변수
	int N, answer = 0, time = 0;

	// 1. 입력 받는다.
	cin >> N;
	vector<P> conference(N);
	for (int i = 0; i < N; ++i)	cin >> conference[i].first >> conference[i].second;

	// 2. 회의 시간을 계산한다.
	// a. 회의 종료 시간을 기준으로 정렬한다
	sort(conference.begin(), conference.end(), compare);
	for (int i = 0; i < N; ++i)
	{
		//cout << conference[i].first << " " << conference[i].second << endl;
		// b. 회의 시간이 짧은 회의를 선택한다.
		// -> 다음 회의 시작 시간이 현재 회의의 종료 시간보다 크다면
		if (conference[i].first >= time)
		{
			// c. 값을 누적
			++answer;
			// d. 시간 변경
			time = conference[i].second;
		}
	}

	// 3. 결과를 출력한다.
	cout << answer;
}

/* 정렬 결과
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
*/