#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1대의 ATM 기기를 이용하는데 걸리는 최소 시간을 구하고싶다.
// 필요속성 : 사람 수, 각각 인출하는데 걸리는 시간
int n, sum;
vector<int> p;

int main()
{
	// 1대의 ATM 기기를 이용하는데 걸리는 최소 시간을 구하고싶다.
	// 1. 속성을 입력받는다.
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		p.push_back(temp);
	}
	// 2. 정렬한다.
	sort(p.begin(), p.end());
	// 3. 시간을 누적한다.
	// ex) 1, 2, 3, 4, 5
	//  1 + (1 + 2) + (1 + 2 + 3) + (1 + 2 + 3 + 4) + (1 + 2 + 3 + 4 + 5)
	// = (1 * 5) + (2 * 4) + (3 * 3) + (4 * 2) + (5 * 1)
	for (int i = 0; i < n; ++i)
		sum += p[i] * (n - i);
	// 4. 출력한다.
	cout << sum;
}