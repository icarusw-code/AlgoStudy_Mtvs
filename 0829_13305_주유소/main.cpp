#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 도시를 이동하는데 필요한 주유비의 최솟값을 구하고 싶다.
// 필요속성 : 도시의 개수, 도시 간 거리, 각 도시의 주유비
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	// 도시를 이동하는데 필요한 주유비의 최솟값을 구하고 싶다.
	int n, min = INT_MAX;
	long long answer = 0;
	// 1. 입력받는다.
	cin >> n;

	// int 일 때, 58점
	vector<long long> distance(n - 1);
	vector<long long> cost(n);

	for (int i = 0; i < n - 1; ++i)	cin >> distance[i];
	for (int j = 0; j < n; ++j)		cin >> cost[j];

	// 2. 주유비를 계산한다.
	for (int k = 0; k < n - 1; ++k)
	{
		// a. 주유소 가격을 비교한다
		if (min > cost[k])	min = cost[k];
		// b. 비용을 누적한다
		answer += min * distance[k];
	}

	// 3. 최솟값을 출력한다.
	cout << answer;
}