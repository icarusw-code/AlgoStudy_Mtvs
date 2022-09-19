//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s;
//	getline(cin, s);
//	
//	for (int i = 0; i < s.length(); i++)
//	{
//		if ((s[i] >= 'a') && (s[i] <= 'z')) //소문자면
//		{
//			if(s[i]-'a'<13)
//				s[i]+=13;//128
//			else
//				s[i]-=13; //102
//		}
//		else if ((s[i] >= 'A') && (s[i] <= 'Z'))//대문자면
//		{
//			if (s[i] - 'A' < 13)
//				s[i] += 13;//128
//			else
//				s[i] -= 13; //102
//		}
//	}
//	cout << s;
//	return 0;
//}