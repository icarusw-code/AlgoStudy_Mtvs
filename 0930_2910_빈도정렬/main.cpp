#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, pair <int, int>> PP;

int N, C, priority;
unordered_map<int, int> frequency;	// (숫자, 빈도)
unordered_map<int, int> order;		// (순서, 숫자)
vector<PP> answer;					// (순서, (숫자, 빈도))

bool cmp(PP a, PP b)
{
	// 빈도수가 같다면 순서에 따라 반환
	if (a.second.second == b.second.second)
		return a.first < b.first;
	else
		return a.second.second > b.second.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// 1. 입력 받는다
	cin >> N >> C;

	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;

		if (frequency.find(temp) == frequency.end())
		{
			frequency.insert({ temp, 1 });
			order.insert({ ++priority, temp });
		}
		else
		{
			++frequency[temp];
		}
	}

	// 2. 결과 도출
	// a. 결과에 (순서, (숫자, 빈도)) 순으로 넣어주고 싶다.
	for (int i = 1; i <= order.size(); ++i)
	{
		answer.push_back({ i, {order.at(i), frequency.at(order.at(i))} });
	}
	// b. 빈도를 기준으로 내림차순 정렬을 한다.
	// (단, 빈도가 같을 경우 순서를 기준으로 오름차순 정렬을 한다.
	sort(answer.begin(), answer.end(), cmp);

	// 3. 결과를 출력한다.
	for (int i = 0; i < answer.size(); ++i)
	{
		for (int j = 0; j < answer[i].second.second; ++j)
		{
			cout << answer[i].second.first << ' ';
		}
	}
}