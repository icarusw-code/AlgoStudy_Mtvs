#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//패턴, 소문자, 별표하나, 
int main() {

	int N;
	cin >> N;
	cin.ignore(); //위 라인 엔터가 밑에 getline에 들어가는 문제 방지

	string pattern;
	getline(cin, pattern); // *한 개 포함된 패턴 입력

	string fileName[100]; //판별할 파일 이름
	for (int i = 0; i < N; i++)
	{
		getline(cin, fileName[i]);
	}

	//패턴 * 기준 왼쪽 글자 수: countLeft, 오른쪽 글자 수: countRight
	//왼쪽부터 다를 때까지 비교하고 같은 글자 수가 countLeft보다 적으면 NE
	//오른쪽부터 왼쪽으로 다를때까지 비교하고 같은 글자 수가 countRight보다 적으면 NE
	int countLeft = 0;
	int countRight = 0;
	for (int i = 0; pattern[i] != '*'; i++)
	{
		countLeft++;
	}
	for (int i = pattern.length() - 1; pattern[i] != '*'; i--)
	{
		countRight++;
	}
	
	for (int i = 0; i < N; i++) // fileName 배열의 i번째 단어
	{
		bool hasPassedLeft = false;

		for (int j = 0; j < countLeft; j++) //j가 비교인덱스인 동시에 같은 글자 count역할
		{
			if (fileName[i][j] != pattern[j])
			{
				cout << "NE" << endl;
				break; //다음 i로
			}
			hasPassedLeft = true;
		}

		if (hasPassedLeft) //왼쪽 판별 통과했을 때만
		{
			for (int k = fileName[i].length() - 1, m = 0;
				m > countRight;
				k--, m++) //k는 비교인덱스, m은 같은 글자 count
			{
				//양쪽 단어의 끝에서 부터
				if (fileName[i][k] != pattern[pattern.length() - 1 - m])
				{
					cout << "NE" << endl;
					break; //다음 i로
				}
			}

			if (i == N - 1)
			{
				cout << "DA";
			}
			else
			{
				cout << "DA" << endl;

			}
		}
	}

}
