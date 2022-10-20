#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	while (true)
	{
		int vowel = 0, consonant = 0;
		bool isAccept = false;
	    // 1. 입력 받는다.
		string s;
		cin >> s;
		// 2. end 가 들어오면 종료한다.
		if (s == "end")	break;
		for (int i = 0; i < s.length(); ++i)
		{
			// 3. 모음이 포함 되었는지 확인한다.
			// -> 모음이 포함 되어 있다면 모음이 연속된 개수를 더한다.
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				// a. 모음이 포함되었는지 체크
				isAccept = true;
				vowel++;
				consonant = 0;
			}
			// 4. 그렇지 않다면 자음의 연속된 개수를 더한다.
			else
			{
				vowel = 0;
				consonant++;
			}

			// 5. 자음이나 모음이 3개 연속인지 확인
			if (vowel >= 3 || consonant >= 3)
			{
				isAccept = false;
				break;
			}

			// 6. 같은 글자가 2번 오는지 확인
			if (i > 0 && s[i - 1] == s[i])
			{
				// a. ee 나 oo 일 경우 패스
				if (s[i] == 'e' || s[i] == 'o')	break;
				isAccept = false;
				break;
			}
		}

		// 7. 결과를 출력한다.
		if (isAccept)
			cout << "<" << s << "> is acceptable.\n";
		else
			cout << "<" << s << "> is not acceptable.\n";
	}
}