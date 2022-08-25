#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	// 알파벳 홀수개 X , 처음 끝 빼고 문자 바뀌면 같은거 2개 이상  , AAABBAABBAABBA ABBA
	int N; // 1 ~ 100
	cin >> N;
	vector<string> inputs;
	int goodWordCount = 0;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		inputs.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		vector<char> stack;
		for (int j = 0; j < inputs[i].length(); j++) {
			if (stack.empty() || stack.back() != inputs[i][j]) {
				stack.push_back(inputs[i][j]);
			}
			else if (stack.back() == inputs[i][j]) {
				stack.pop_back();
			}
		}
		/*vector<char> :: iterator iter;
		for (iter = stack.begin(); iter != stack.end(); iter++)
		{
			cout << *iter << endl;
		}*/

		if (stack.empty())
			goodWordCount++;
	}

	cout << goodWordCount;

}	