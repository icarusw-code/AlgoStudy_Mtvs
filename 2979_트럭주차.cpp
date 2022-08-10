#include <bits/stdc++.h>

using namespace std;

int a, b, c, ans = 0;
int arr[101];

int main()
{
    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++)
    {
        int start, end;
        cin >> start >> end;
        for(int j = start ; j < end; j ++)
        {
            arr[j] += 1;
        }
    }
    for(int i = 1; i <= 100; i ++)
    {
        if(arr[i] == 1) ans += arr[i] * a;
        else if(arr[i] == 2) ans += arr[i] * b;
        else ans += arr[i] * c;
    }

    cout << ans;
    return 0;
}

