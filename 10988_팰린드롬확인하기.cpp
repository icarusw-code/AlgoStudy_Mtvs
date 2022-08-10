#include <bits/stdc++.h>

using namespace std;

// string s;
// int cnt;

// int main()
// {
//     cin >> s;

//     for(int i = 0; i < s.length()/2 ; i++)
//     {
//         if(s[i] != s[s.length() - 1 - i])
//         {
//             cnt += 1;
//         }
//     }

//     if(cnt == 0) cout << 1;
//     else cout << 0;

//     return 0;
// }

string s, tmp;
int main()
{
    cin >> s;
    tmp = s;
    reverse(tmp.begin(), tmp.end());
    if(tmp == s) cout << 1<< "\n";
    else cout << 0 << "\n";
    return 0;
}