#include <iostream>

using namespace std;
// 농구 선수의 이름을 입력받아 성의 첫 글자가 같은 선수 5명을 선발하고 싶다.
// 만약 성의 첫 글자가 같은 선수가 5명보다 작다면 기권 (PREDAJA)
// 필요속성 : 농구 선수의 수, 선수들의 이름, 기권 여부
const int ALPHABET_MAX = 26;
int main()
{
	// 필요속성 : 농구 선수의 수, 선수들의 이름, 기권 여부
	int playerCount = 0;
	int surName[ALPHABET_MAX] = { 0 };
	bool isPredaja = true;
	// 1. 농구 선수의 수를 입력받는다.
	cin >> playerCount;
	// 2. 선수들의 이름을 입력 받는다.
	for (int i = 0; i < playerCount; i++)
	{
		string name;
		cin >> name;
		// 3. 선수들의 성의 첫 글자를 비교한다.
		// -> 성의 첫 글자를 카운팅
		surName[name[0] - 'a']++;
	}
	// 4. 선수 5명을 선발할 수 있다면 선발하고 싶다.
	for (int i = 0; i < ALPHABET_MAX; i++)
	{
		if (surName[i] >= 5)
		{
			isPredaja = false;
			cout << static_cast<char>(i + 'a');
		}
	}
	// 5. 그렇지 않으면 경기를 포기한다.
	if (isPredaja)	cout << "PREDAJA" << endl;
}
