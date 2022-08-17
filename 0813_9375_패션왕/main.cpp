#include <iostream>
#include <map>

using namespace std;

// 똑같은 조합의 옷을 입지 않고 며칠 동안 밖에 나갈 수 있는지 구해보자.
// 필요속성 : 테스트 케이스, 갖고 있는 의상의 수, 의상정보
int t, n;
map<string, int> clothes;
int main()
{
	// 똑같은 조합의 옷을 입지 않고 며칠 동안 밖에 나갈 수 있는지 구해보자.
	// -> 알몸을 제외한 모든 경우의 수를 따지기
	// 1. 테스트 케이스를 입력받는다.
	cin >> t;
	
	for (int i = 0; i < t; ++i)
	{
		// 2. 갖고 있는 의상의 수를 입력받는다.
		cin >> n;

		for (int j = 0; j < n; ++j)
		{
			string name, kind;
			// 3. 옷의 이름과 종류를 입력받는다.
			// -> 옷의 이름은 같은 이름을 가지지 않기 때문에 계산에 필요 x
			cin >> name >> kind;
			// 4. 의상 종류의 수를 증가 시킨다.
			// -> 의상 종류의 value 값을 증가 시킨다.
			if (clothes.find(kind) == clothes.end())
				clothes.insert(make_pair(kind, 1));
			else
				++clothes[kind];
		}
		// 5. 조합을 계산한다.
		int answer = 1;
		for (map<string, int>::iterator iter = clothes.begin(); iter != clothes.end(); ++iter)
		{
			// a. 옷의 종류의 숫자 + 입지 않은 경우
			answer *= iter->second + 1;
		}
		cout << answer - 1 << endl;
		// ※ map 을 비워주지 않으면 값이 누적되어 이상한 결과가 나옴
		clothes.clear();
	}
}