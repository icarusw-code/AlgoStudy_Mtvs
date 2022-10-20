#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int H, W;
vector<string> cloud;
vector<vector<int>> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// 1. 입력 받기
	cin >> H >> W;

	answer.assign(H, vector<int>(W, -1));
	
	for (int i = 0; i < H; ++i)
	{
		string s;
		cin >> s;
		cloud.push_back(s);

		// 2. 문자열 숫자로 결과 값으로 변환
		for (int j = 0; j < W; ++j)
		{
			if (cloud[i][j] == 'c')
			{
				answer[i][j] = 0;
			}
		}
		
		// 3. 탐색 하면서 결과 값 증가
		for (int j = 0; j < W - 1; ++j)
		{
			if (answer[i][j] >= 0 && answer[i][j + 1] == -1)
			{
				answer[i][j + 1] = answer[i][j] + 1;
			}
		}
	}

	// 4. 결과 출력
	for(int i=0; i<H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			cout << answer[i][j] << " ";
		}
		cout << '\n';
	}
}