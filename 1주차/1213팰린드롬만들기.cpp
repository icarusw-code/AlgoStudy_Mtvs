#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//패턴, 소문자, 별표하나, 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	getline(cin, input);

	//첫 문자 홀수면 -> 다음 문자는 짝수여야??? XXX
	//홀수개인 알파벳은 하나여야만. -> 알파벳들이 모두 짝수인 경우1 or 홀수개 알파벳이 하나이고 나머지 모두 짝수개인 경우2
	// 경우1: 사전 순대로 반개씩 출력 ex) AAAA BBBB CC -> AABBC ->AABBCCBBAA
	// 경우2: 홀수 인 알파벳 하나를 가운데 기준으로 두고, 앞에 절반 씩 출력 AAAA BBB CC DDDD -> AABCDD B DDCBAA

	// 알파벳 개수 세서 배열에 넣는다.
	int alphabetCount[26] = {0, };
	for (int i = 0; i < input.length(); i++) {
		alphabetCount[input[i] - 65]++;
	}

	// count 배열에서 0이 아닌 것만 추출.

	string answer = "";
	string half = "";
	int oddCount = 0;
	int oddIndex = -1;
	for (int i = 0; i < 26; i++)
	{
		//cout << alphabetCount[i];
		

		if (alphabetCount[i] % 2 == 0) {
			for (int j = 0; j < alphabetCount[i] / 2; j++) {
				half += (char)(i + 'A');
			}
		}
		else {
			for (int j = 0; j < alphabetCount[i] / 2; j++) {
				half += (char)(i + 'A');
			}
			//cout << "oddcount++" << endl;
			oddCount++;
			oddIndex = i;
		}
		//
	}

	if (oddCount == 0) //홀수가 없으면
	{
		answer += half;
		reverse(half.begin(), half.end());
		answer += half;
		cout << answer;
	}
	else if (oddCount == 1)
	{
		answer += half;
		//cout << half << endl;
		//cout << char(alphabetCount[oddIndex] + 63) << endl;
		answer += char(oddIndex + 'A');
		reverse(half.begin(), half.end());
		//cout << half << endl;
		answer += half;
		cout << answer;
	}
	else if (oddCount > 1)
	{
		cout << "I'm Sorry Hansoo";
	}
}