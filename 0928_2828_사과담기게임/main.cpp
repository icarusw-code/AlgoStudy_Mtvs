#include <iostream>
#include <vector>

using namespace std;

int N, M, J, answer;
vector<int> apple;

int main()
{
	// 1. 입력 받기
	cin >> N >> M >> J;
	apple.assign(J, 0);

	for (int i = 0; i < J; ++i)	cin >> apple[i];

	// a. 바구니 크기 설정
	int left = 1;
	int right = M;
	// 2. 탐색하여 결과를 출력한다.
	for (int i = 0; i < J; ++i)
	{
		// a. 이동할 거리 설정
		int temp = 0;
		// b. 사과가 떨어지는 칸이 바구니 범위 안에 있으면 넘어간다.
		if (left <= apple[i] && apple[i] <= right)	continue;
		// c. 사과가 떨어지는 칸이 바구니의 left 보다 작다면 해당 칸 까지 이동한다.
		if (apple[i] < left)
		{
			temp = left - apple[i];
			left -= temp;
			right -= temp;
		}
		// d. 사과가 떨어지는 칸이 바구니의 right 보다 크다면 해당 칸 까지 이동한다.
		else if (apple[i] > right)
		{
			temp = apple[i] - right;
			left += temp;
			right += temp;
		}
		// e. 결과 더하기
		answer += temp;
	}

	// 3. 결과 출력
	cout << answer;
}