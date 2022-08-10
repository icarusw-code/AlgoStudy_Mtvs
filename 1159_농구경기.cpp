#include <bits/stdc++.h>

using namespace std;

int n, cnt[26];
string name, tmp;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> name;
        cnt[name[0] - 'a'] ++;
    }

    for(int i=0; i < 26; i++)
    {
        if(cnt[i] >= 5)
        {
            tmp += (i + 'a');
        }
    }    
    if(tmp.size() != 0) cout << tmp << "\n";
    else cout << "PREDAJA" << "\n";
    
    return 0;
}