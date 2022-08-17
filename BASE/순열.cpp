#include <bits/stdc++.h>

using namespace std;

int a[3] = {1, 2, 3};
vector<int> v;

void printV(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void Permutation(int n, int r, int level)
{
    if(r == level)
    {
        printV(v);
        return;
    }
    for(int i = level; i < n; i ++)
    {
        swap(v[i], v[level]);
        Permutation(n, r, level + 1);
        swap(v[i], v[level]);
    }
    return;
}

int main()
{
    for(int i = 0; i < 3; i++)
    {
        v.push_back(a[i]);
    }
    Permutation(3, 3, 0);
    return 0 ;
}