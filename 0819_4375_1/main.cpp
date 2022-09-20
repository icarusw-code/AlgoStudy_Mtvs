#include <iostream>

using namespace std;

// 2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 1로만 이루어진 n의 배수를 찾아 가장 작은 숫자의 자리수를 출력하고 싶다.
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// 2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때
	// 1로만 이루어진 n의 배수를 찾아 가장 작은 숫자의 자리수를 출력하고 싶다.
    
	while (cin >> n)
	{
		int temp = 1;
		int digit = 1;
		
		// 1. 1 로만 n 의 배수 중 가장 작은 수를 찾고싶다.
		// -> n 의 배수를 직접 구하는 방식대신 1, 11, 111 ... 의 값만 계산한다.
		// -> modular 연산을 활용한다.
		while (temp % n != 0)
		{
			temp = temp * 10 + 1;
			temp %= n;
			++digit;
		}
		// 2. 자리수를 출력하고 싶다.
		cout << digit << '\n';
	}
}
