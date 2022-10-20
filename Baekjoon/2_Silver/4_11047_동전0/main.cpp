#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 동전의 종류별로 사용하여 입력받은 금액에 필요한 최소 동전 갯수를 구하고싶다.
// 필요속성 : 동전 종류의 수, 금액, 동전의 가치
int n, k, answer;
vector<int> a;

int main()
{
	// 동전의 종류별로 사용하여 입력받은 금액에 필요한 최소 동전 갯수를 구하고싶다.
	// 1. 입력받아서
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	// 2. 필요한 동전의 갯수를 계산하고
	// -> 동전의 가치를 큰 값부터 비교해서 필요한 단위를 찾아서
	// -> 해당 값 만큼 계산한다.
	for (int i = n; --i >= 0;)
	{
		// a. 동전의 가치가 금액보다 크면 continue
		if (a[i] > k)	continue;
		// b. 그렇지 않다면 갯수만큼 결과에 더해준다.
		answer += k / a[i];
		k %= a[i];
		if (k <= 0)	break;
	}
	// 3. 결과를 출력하고 싶다.
	cout << answer;
}