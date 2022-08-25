#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
	int n, count=0;
	string* words;
	stack<int> s;
	char top;
	
	cin >> n;

	// 단어 입력 받기
	words = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> words[i];
	}

	// 각 단어를 판별
	for (int i = 0; i < n; i++)
	{
		for (char alpha : words[i])
		{
			// 스택이 비었으면 일단 삽입
			if (s.empty())
			{
				s.push(alpha);
			}
			// alpha와 top이 같으면 top을 뺀다.
			else if (s.top() == alpha)
			{
				s.pop();
			}
			// alpha와 top이 다르면 alpha를 스택에 삽입
			else
			{
				s.push(alpha);
			}
		}
		// 스택에 남은 값이 없으면 좋은 단어로 카운트
		if (s.empty())
		{
			count++;
		}
		// 스택 비우기
		while (!s.empty())
		{
			s.pop();
		}
	}
	cout << count << "\n";
	
	return 0;
}