#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 두 개의 재료로 만드는 갑옷을 재료에 따라 몇개 만들 수 있는지 알고싶다.
// 필요속성 : 재료의 개수, 갑옷의 조합 번호, 재료의 고유번호
int N, M;
vector<int> material;
int answer;
int main()
{
	// 두 개의 재료로 만드는 갑옷을 재료에 따라 몇개 만들 수 있는지 알고싶다.
	// 1. 재료의 개수와 갑옷의 조합 번호를 입력 받는다.
	cin >> N >> M;
	// 2. 재료의 고유 번호를 입력받는다.
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		material.push_back(temp);
	}
	// 3. 정렬한다.
	sort(material.begin(), material.end());
	// 4. 갑옷을 만들 수 있는 조건을 확인한다.
	// -> 두 재료의 합이 M 과 일치하는지 확인한다.
	// -> 정렬한 벡터의 시작과 끝의 합과 비교하며 index 를 변경한다.
	int start = 0;
	int end = N - 1;
	while (start < end)
	{
		// a. 두 재료의 고유번호의 합과 조합 번호가 일치하면 카운팅한다.
		if (material[start] + material[end] == M)
		{
			++answer;
			++start;
			--end;
		}
		// b. 두 재료의 고유번호의 합보다 조합 번호가 작으면 start index 를 증가시킨다.
		else if (material[start] + material[end] < M)	++start;
		// c. 두 재료의 고유번호의 합보다 조합 번호가 크면 end index 를 증가시킨다.
		else	--end;
	}
	// 5. 결과를 출력한다.
	cout << answer << '\n';
}