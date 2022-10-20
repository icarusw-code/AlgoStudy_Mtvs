#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// 1. 입력 받기
	int N, answer = 665, cnt = 0;
	cin >> N;

	// 2. 반복을 돌면서 결과 도출
	// -> 문자열로 변환시켜서 find 로 찾는다.
	while (cnt != N)
	{
		string s = to_string(++answer);

		// a. 문자열에 666 이 포함되었다면
		// ※ string::find("찾을내용")
		//	-> 찾는 내용이 없다면 string::npos 를 return
		//	-> npos 는 no position
		if (s.find("666") != string::npos)
		{
			// b. 종말의 횟수를 증가
			cnt++;
		}
	}

	// 3. 결과 출력
	cout << answer;
}