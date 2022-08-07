#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";

    while((pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());

        cout << "input : " <<  input << "\n";
    }
    
    ret.push_back(input);
    return ret;
}


int main()
{
    string s = "aa.bb.cc.dd.ee.ff.gg";
    vector<string> a = split(s, ".");

    cout << a[3] << "\n";

    // for(string b : a) cout << b << "\n";
}

