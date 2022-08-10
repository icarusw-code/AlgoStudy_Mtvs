#include <bits/stdc++.h>

using namespace std;

string s, tmp;
int cnt = 0;

int main()
{
    cin >> s;
    tmp = s;
    reverse(tmp.begin(), tmp.end());

    if(s == tmp)
    {
        cout << 0;
    }
    else
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != tmp[i]) cnt++;
        }

        cout << cnt / 2;
    }

    return 0;
}