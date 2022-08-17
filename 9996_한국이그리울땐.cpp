#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string pattern;
    vector<string> files, answer;
    
    cin >> n;
    cin >> pattern;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        files.push_back(s);
    }

    char start, end;
    start = pattern[0];
    end = pattern[pattern.length() - 1];

    for(int i = 0; i < n - 1; i++)
    {

        if(files[i][0] == start && files[i][files[i].length() - 1] == end)
        {
            cout << "DA\n";
        }
        else
        {
            cout << "NE\n";
        }
    }
    
    if(files[n-1][0] == start && files[n-1][files[n-1].length() - 1] == end)
    {
        cout << "DA";
    }
    else
    {
        cout << "NE";
    }

    return 0;
}