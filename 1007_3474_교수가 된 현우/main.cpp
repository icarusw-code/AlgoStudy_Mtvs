#include <iostream>
#include <vector>

using namespace std;

int T, multiple;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// 1. 입력받기
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;

		// 2. 5의 배수에 따른 소인수 분해 계산
		// -> 10 이 나오는 경우는 (2 x 5) 의 경우만 존재
		// -> 10 = (2 x 5), 20 = 2 x (2 x 5), 30 = 3 x (2 x 5), 40 = 4 x (2 x 5), 50 = 5 x (2 x 5)
		// -> 5! = 5 x 4 x 3 x 2 x 1 >> (5 x 2) 가 1번 등장
		// -> 10! = 10 x 9 x 8 x 7 x 6 x 5 x 4 x 3 x 2 x 1 >> (5 x 2) 가 2번 등장
		// -> 25! = 25 x 24 x ... x 2 x 1 >> (5 x 2) 가 6번 등장
		// -> 따라서 N! 에서 5 가 몇 번 나오는지 확인하면 된다.
		
		// a. 5 의 개수 및 배수 초기화
		int cnt = 0;
		multiple = 5;
		// b. 5 가 몇 번 나오는지 확인
		while (multiple <= N)
		{
			cnt += N / multiple;
			multiple *= 5;
		}
		answer.push_back(cnt);
	}

	// 3. 결과 출력
	for (vector<int>::iterator it = answer.begin(); it != answer.end(); ++it)
		cout << *it << '\n';
}