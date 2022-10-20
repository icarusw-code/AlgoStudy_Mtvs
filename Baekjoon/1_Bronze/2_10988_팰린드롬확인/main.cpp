#include <iostream>

using namespace std;
// 팰린드롬 판별하기
// 필요속성 : 문자, 비교할 인덱스
int Palindrome1()
{
	// 필요속성 : 문자, 비교할 인덱스
	string s;
	cin >> s;
	int start = 0, end = s.length() - 1;
	int center = s.length() / 2;

	// 반복문을 돌면서 문자를 비교
	for (int i = 0; i < center; i++)
	{
		if (s[start] == s[end])
		{
			start++;
			end--;
		}
		// 팰린드롬이 아니면 0을 출력하고 return
		else
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}
// 팰린드롬을 만들기 위해 바꿔하는 문자의 최소 개수 구하기
// 필요속성 : 문자, 비교할 인덱스, 카운팅
int Palindrome2()
{
	// 필요속성 : 문자, 비교할 인덱스, 카운트
	string s;
	cin >> s;
	int start = 0, end = s.length() - 1;
	int center = s.length() / 2;
	int count = 0;

	// 반복문을 돌면서 문자를 비교
	for (int i = 0; i < center; i++)
	{
		if (s[start] == s[end])
		{
			start++;
			end--;
		}
		// 팰린드롬이 아니면 카운팅
		else	count++;
	}
	cout << count;
}

int main()
{
	Palindrome1();
	Palindrome2();
}