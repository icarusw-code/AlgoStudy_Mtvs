#include <iostream>

using namespace std;

// A^B % C 결과를 출력하고 싶다.
int A, B, C, result;

// A^B%C 계산
int POW(int a, int b, int c)
{
	if (b == 0)	return 1;
	else if (b == 1) return a % c;

	long long temp = POW(a, b/2, c);
	if (b % 2 == 0)	return (temp * temp) % c;
	//else	return (temp * temp * a) % c;
	else	return ((temp * temp) % c * a % c) % c;
}

int main()
{
	cin >> A >> B >> C;
	cout << POW(A, B, C);
}