#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {

	// >> 13글자 밀기, 숫자 띄어쓰기는 그대로
	// char A 65 Z 90 a 97 z 122/ 
	string S;
	//cin >> S; //getline
	getline(cin, S);
	//A0 -> N13
	char small[26] = { 'a', 'b', 'c', 'd', 'e','f', 'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char BIG[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

	for (int i = 0; i < S.length(); i++) {
		for (int j = 0; j < 26; j++) {
			if (S[i] == small[j]) {
				if (j > 13)
				{
					S[i] = small[j - 13];
					break;
				}
				else
				{
					S[i] = small[j + 13];
					break;
				}
				//cout << S[i] << endl;
			}
			else if (S[i] == BIG[j]) {
				if (j > 13)
				{
					S[i] = BIG[j - 13];
					break;
				}
				else
				{
					S[i] = BIG[j + 13];
					break;
				}
				//cout << S[i] << endl;
			}
			
				//cout << "nothing equal" << endl;;
		}
		cout << S[i];
	}
	





	//int StoInt[120];
	//for (int i = 0; i < S.length(); i++) {
	//	StoInt[i] = S[i]; // int형을 저장
	//	//78~90, 110~122 은
	//	//13옮겨도 Z나 z넘어가지 않는 문자면
	//	if (StoInt[i] < 78) {
	//		StoInt[i] += 13;
	//	}
	//	else if (78 <= StoInt[i] < 91) {
	//		StoInt[i] += 13 - 26;
	//	}
	//	else if (97 <= StoInt[i] < 110) {
	//		StoInt[i] += 13;
	//	}
	//	else if (StoInt[i] >110) {
	//		StoInt[i] += 13 - 26;
	//	}
	//	

	//}



}

//string 형 
