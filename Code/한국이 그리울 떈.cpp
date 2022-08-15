#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int count;
	string pattern;
	string s;
	int starPoint;
	vector<string> answer;
	
	cin >> count;
	cin>> pattern;
	starPoint = pattern.find('*');

	for (int i = 0; i < count; ++i)
	{
		bool flag=true;
		cin>> s;
		//예외처리
		if(s.size()< pattern.size()-1)
			flag=false;

		//앞문자 비교
		for (int j = 0; j < starPoint; ++j)
		{
			if(s[j]!=pattern[j])
			{
				flag=false;
				break;
			}
		}
		if (flag)
		{
			//뒤 문자 비교
			int tempCount=0;
			for (int k = pattern.size() - 1; k > starPoint; k--)
			{
				if (s[s.size() - 1-tempCount] != pattern[k])
				{
					flag = false;
					break;
				}
				tempCount++;
			}

		}
		if(flag)
			answer.push_back("DA");
		else
			answer.push_back("NE");
	}
	for (int m = 0; m < answer.size(); m++)
	{
		cout <<answer[m];
		if(m != answer.size()-1)
			cout<< "\n";
	}
	return 0;
}

//Test Case
/*
3
abc*def
abcdewrfgwlkjdef
abckoekwfjefgef
abgrwejgwedef
DA
NE
NE
*/
