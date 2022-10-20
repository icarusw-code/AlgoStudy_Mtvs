#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
    
	// 1. 입력 받기
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		stack<char> vps;
		string s;
		cin >> s;

		// 2. 스택을 이용해 결과를 도출
		// -> 왼쪽 괄호 일 때만 push
		for (int j = 0; j < s.length(); ++j)
		{
			// a. 왼쪽 괄호라면 push
			if (s[j] == '(')	vps.push(s[j]);
			// b. 오른쪽 괄호라면
			else
			{
				// c. 스택이 비었다면 VPS 가 아님
				if (vps.empty())
				{
					vps.push(s[j]);
					break;
				}
				// d. 스택이 비어 있지 않다면
				// -> '(' 가 스택에 있다는 뜻
				else vps.pop();
			}
		}

		// 3. 결과 출력
		if (vps.empty())	cout << "YES\n";
		else	cout << "NO\n";
	}
}