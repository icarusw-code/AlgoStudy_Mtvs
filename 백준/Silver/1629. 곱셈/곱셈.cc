#include <iostream>

using namespace std;

int myPow(long long int n, long long int m, long long int C)
{
	long long int res;
	if (m == 1)
		return n % C;

	res = myPow(n, m / 2, C) % C;
	if (m % 2 == 1)
		return res * res % C * n % C;
	return res * res % C;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int A, B, C;
	double pow_double;
	int res;

	cin >> A >> B >> C;
	
	res = myPow(A, B, C);
	
	cout << res;
	
	return 0;
}