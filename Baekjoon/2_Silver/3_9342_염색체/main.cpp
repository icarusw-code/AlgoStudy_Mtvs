#include <iostream>
#include <regex>

using namespace std;

void FastIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main()
{
	FastIO();

	// 1. 입력 받기
	int T;
	cin >> T;

	// 2. 정규표현식 설정
	regex re("^[A-F]?A+F+C+[A-F]?$");

	for (int i = 0; i < T; ++i)
	{
		string s;
		cin >> s;

		// 3. 문자열과 일치하는 판별 후 결과 출력
		if (regex_match(s, re))
			cout << "Infected!\n";
		else
			cout << "Good\n";
	}
}

/*
* regex re("^[A-F]?A+F+C+[A-F]?$");
* regex re("(^[A-F]?A+F+C+[A-F]?$)");
* regex re(R"(^[A-F]?A+F+C+[A-F]?$)");
*/