#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 스타벅스에서 손님이 주려던 팁의 최댓값을 출력하고 싶다.
// 필요속성 : 사람 수, 팁

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	// 스타벅스에서 손님이 주려던 팁의 최댓값을 출력하고 싶다.
	// 1. 입력받는다.
	int n;
	long long answer = 0;
	cin >> n;

	vector<int> tips(n);
	for (int i = 0; i < n; ++i)	cin >> tips[i];

	// 2. 팁을 계산한다.
	// a. 팁을 내림차순으로 정렬
	//sort(tips.begin(), tips.end(), greater<int>());
	sort(tips.rbegin(), tips.rend());
	for (int i = 0; i < n; ++i)
	{
		// b. 계산한 값이 음수가 아니면 더해준다
		if (tips[i] - i > 0)	answer += tips[i] - i;
	}
	// 3. 결과를 출력하고 싶다.
	cout << answer;
}