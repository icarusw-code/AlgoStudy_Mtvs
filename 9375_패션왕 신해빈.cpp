#include <bits/stdc++.h>

using namespace std;

int t, n;
string a,b;

int main()
{
	cin >> t;
	while (t--)
	{
		map<string, int> wear;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			wear[b] ++;
		}

		long long tmp = 1;

		for (auto w : wear) 
		{
			tmp *= ((long long)w.second + 1);
		}

		tmp -= 1;

		cout << tmp << "\n";

	}
}