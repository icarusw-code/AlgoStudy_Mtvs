#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
// A, B 로 이루어진 문자열을 아치형으로 매칭시켜서 겹치지 않는지 판별하고 싶다.
// 필요속성 : 단어의 수
int N, result;

int main()
{
	// A, B 로 이루어진 문자열을 아치형으로 매칭시켜서 겹치지 않는지 판별하고 싶다.
	// 1. 단어의 수를 입력받는다.
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		// 2. 문자열을 입력받는다.
		string s;
		cin >> s;

		// ※ 문자열의 길이가 홀수라면 좋은 단어가 될 수 없음.
		if (s.length() % 2 != 0)	continue;
		
        stack<char> ab;

		for (int j = 0; j < s.length(); ++j)
		{
			// 3. 아치형으로 매칭 시키고 싶다.
			if (ab.empty())	ab.push(s[j]);
			else
			{
				// a. stack 에 top 문자와 비교를 해서 일치하면 pop, 다르면 push 을 하고
				if (ab.top() == s[j])	ab.pop();
				else	ab.push(s[j]);
			}
			// b. 반복이 종료된 후 stack 이 비었는지 체크해서 비었으면 카운팅한다.
			if (j == s.length() - 1 && ab.empty())	++result;
		}
	}

	// 4. 결과를 출력하고 싶다.
	cout << result;
}