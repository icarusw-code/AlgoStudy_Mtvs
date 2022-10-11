// 2 의 제곱수 N 이 주어진다.
// 가로, 세로 N/2 만큼 분할 한다.
// 재귀를 통해 해당 구역을 또 분할 한다.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int  N;
string answer;
vector<vector<int>> video;

void Compression(int size, int x = 0, int y = 0)
{
	// 1. size 가 1인 경우
	if (size == 1)
	{
		// a. 결과를 누적하고 함수 탈출 
		answer += to_string(video[x][y]);
		return;
	}

	// 2. 반복문을 실행하면서 탐색한다.
	for (int i = x; i < x + size; ++i)
	{
		for (int j = y; j < y + size; ++j)
		{
			// a. 만약 기존 값이 탐색한 위치의 값과 다르다면
			if (video[x][y] != video[i][j])
			{
				// b. 괄호를 열고
				answer += '(';
				// c. 4 분할을 재실행한다. (재귀)
				// -> 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래 순서
				Compression(size / 2, x, y);
				Compression(size / 2, x, y + size / 2);
				Compression(size / 2, x + size / 2, y);
				Compression(size / 2, x + size / 2, y + size / 2);
				// d. 괄호를 닫고
				answer += ')';
				// e. 함수 종료
				return;
			}
		}
	}

	// 3. 탐색이 끝났다면 결과를 누적한다.
	answer += to_string(video[x][y]);
}

int main()
{
	// 1. 입력 받기
	cin >> N;

	video.assign(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf_s("%1d", &video[i][j]);

	// 2. 재귀 호출
	Compression(N);

	// 3. 결과 출력
	cout << answer;
}