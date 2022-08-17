#include <iostream>
#include <string>

using namespace std;
// 입력 받은 문자열의 영어 알파벳을 13글자 밀어서 암호문을 만들고 싶다.
// 단, 알파벳이 아닌 글자는 원본을 유지한다.
// 필요속성 : 변환할 문자열
const int SHIFT_NUMBER = 13;
int main()
{
	// 필요속성 : 변환할 문자열
	string s;
	// 1. 문자열을 입력받는다.
	getline(cin, s);
	// 2. 알파벳을 13글자 밀어서 암호문을 만들고 싶다.
	for (int i = 0; i < s.length(); i++)
	{
		// 단, 알파벳이 아닌 글자는 원본을 유지한다.
		// -> 알파벳만 바꾼다.
		// 3. 알파벳인지 판별하고
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			// 4. 변환해준다.
			if (s[i] + SHIFT_NUMBER > 'z')	s[i] -= SHIFT_NUMBER;
			else	s[i] += SHIFT_NUMBER;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i] + SHIFT_NUMBER > 'Z')	s[i] -= SHIFT_NUMBER;
			else	s[i] += SHIFT_NUMBER;
		}
	}
	// 5. 변환한 암호문을 출력한다.
	cout << s;
}