#include <string>
#include<iostream>
using namespace std;

bool solution(string s, string t)
{
	bool answer = true;
	string longS="";
	string shortS="";
	//�� ���� ª�� ���� �����ؾ� ��
	longS = (s.size()>=t.size())? s: t;
	shortS = (s.size() < t.size()) ? s : t;

	//�� ���� �ձ�
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
