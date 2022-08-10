#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string str;
int arr[26];

int main()
{
    cin >> str;
    for(char a : str)
    {
        arr[a - 'a']++ ;
    }
    
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}