#include <string>
#include<iostream>
using namespace std;

bool solution(string s, string t)
{
	bool answer = true;
	string longS="";
	string shortS="";
	//긴 쪽이 짧은 쪽을 포함해야 함
	longS = (s.size()>=t.size())? s: t;
	shortS = (s.size() < t.size()) ? s : t;

	//긴 문장 잇기
	longS += longS;

	for(int i=0; i<longS.size(); ++i)
	{
		if(longS[i] == shortS[i%shortS.size()])
			continue;
		else
		{
			answer=false;
			break;
		}
	}
	cout << (answer? "true":"false")<<endl;
	return answer;
}

//int main()
//{
//	solution("ABCAB", "ABC");
//}
