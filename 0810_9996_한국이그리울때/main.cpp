#include <iostream>
#include <string>

using namespace std;

// 패턴과 파일 이름이 모두 주어졌을 때, 각각의 파일 이름이
// 패턴과 일치하는지 아닌지를 구해 일치하면 "DA", 일치하지 않으면 "NE"를 출력하고 싶다.
// 필요속성 : 파일의 개수, 패턴, 파일의 이름, 결과
int main()
{
	// 필요속성 : 파일의 개수, 패턴, 파일의 이름, 결과
	// 1. 필요속성들을 입력 받는다.
	int n;
	cin >> n;
	string pattern[3], answer = "";
	cin >> pattern[0];
	// 2. 패턴을 파악한다.
	int index = pattern[0].find('*');
	pattern[1] = pattern[0].substr(0, index);
	pattern[2] = pattern[0].substr(index + 1);

	for (int i = 0; i < n; i++)
	{
		string fileName;
		cin >> fileName;
		// 3. 패턴과 일치하는지 판별하고 싶다.
		// a. 비교할 패턴이 입력받은 파일이름보다 크다면 반드시 불일치
		// -> RunTimeError_OutOfRange 방지
		if (pattern[1].size() + pattern[2].size() > fileName.size())
		{
			answer += "NE\n";
		}
		// b. 직접 비교
		// 패턴 1 (* 앞) 과 입력받은 파일이름의 0 ~ index 까지 잘라서 일치하는지 판별
		// 패턴 2 (* 뒤) 와 입력받은 파일이름의 end ~ 패턴 2 의 길이만큼 잘라서 일치하는지 판별
		else if (pattern[1].compare(fileName.substr(0, index)) == 0
				&& pattern[2].compare(fileName.substr(fileName.length() - pattern[2].length())) == 0)
		{
			answer += "DA\n";
		}
		else
		{
			answer += "NE\n";
		}
	}

	// 4. 결과를 출력하고 싶다.
	cout << answer;
}