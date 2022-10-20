#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
bool isStream;
vector<string> answer;

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string s, stream;
		// 1. 입력받기
		cin >> s;

		// 2. 문자열에서 숫자 가져오기
		for (int j = 0; j < s.length(); ++j)
		{
			// 3. 숫자 배열을 원래 값으로 변환 해서 결과에 저장
			// a. 문자열에 숫자가 들어 있다면
			if (isdigit(s[j]))
			{
				// b. 연속적인 수를 파악하고 저장
				isStream = true;
				if (stream.length() == 1 && stream == "0")	stream = "";
				stream += s[j];
			}
			else
			{
				isStream = false;
			}

			// 4. 저장된 숫자를 parsing
			// a. 숫자가 저장되었는지 확인하고
			if (stream.length() > 0)
			{
				// b. 연속이 끊겼거나 마지막 문자열에 도달했다면
				if (isStream == false || j == s.length() - 1)
				{
					// c. 결과에 저장
					answer.push_back(stream);
					// d. stream 초기화
					stream = "";
				}
			}
		}
	}

	// 5. 정렬
	sort(answer.begin(), answer.end(), cmp);

	// 6. 결과 출력
	for (vector<string>::iterator it = answer.begin(); it != answer.end(); ++it)
		cout << *it << endl;
}