#include <bits/stdc++.h>

using namespace std;

int n;
string file, pattern, pre, suf;
int main()
{
    cin >> n;
    cin >> pattern;

    int pos = pattern.find("*");
    pre = pattern.substr(0, pos);
    suf = pattern.substr(pos + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> file;
        if(pre.size() + suf.size() > file.size())
        {
            cout << "NE" <<"\n";
        }
        else
        {
            if(pre == file.substr(0, pre.size()) && suf == file.substr(file.size() - suf.size()))
            {
                cout << "DA" << "\n";
            }
            else
            {
                cout << "NE" << "\n";
            }
        }
    }

    return 0;
}