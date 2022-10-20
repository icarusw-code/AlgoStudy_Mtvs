#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	while (true)
	{
		stack<char> st;
		// 1. 입력 받기
		string s;
		getline(cin, s);

		if (s == ".")	break;

		// 2. 문자열 비교
		for (int i = 0; i < s.length(); ++i)
		{
			// a. 왼쪽 괄호라면 push
			if (s[i] == '(' || s[i] == '[')	st.push(s[i]);
			// 3. 오른쪽 소괄호
			else if (s[i] == ')')
			{
				// a. 짝을 이루는지 확인
				// -> 비어있는지 확인 안하면 오류
				if (st.empty() == false && st.top() == '(')	st.pop();
				// b. 그렇지 않다면 그냥 push 하고 break
				else
				{
					st.push(s[i]);
					break;
				}
			}
			// 4. 오른쪽 대괄호
			else if (s[i] == ']')
			{
				// a. 짝을 이루는지 확인
				if (st.empty() == false && st.top() == '[')	st.pop();
				// b. 그렇지 않다면 그냥 push 하고 break
				else
				{
					st.push(s[i]);
					break;
				}
			}
		}

		// 5. 결과 출력
		if (st.empty())	cout << "yes\n";
		else cout << "no\n";
	}
}