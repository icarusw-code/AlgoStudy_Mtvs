#include <iostream>
#include <vector>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int a[1004][1004];
bool visited[1004][1004];

int n, m, nx, ny, answer;

void dfs(int y, int x)
{
    cout << y << " : " << x << "\n";
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(a[ny][nx] == 0 && !visited[ny][nx])
        {
            dfs(ny, nx);
        }
    }
    
    return;
}


int main()
{
    cin >> n >> m;
    
    // 입력
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == 0 && !visited[i][j])
            {
                answer ++;
                dfs(i, j);
            }
        }
    }

    cout << answer << "\n";
    return 0;
}