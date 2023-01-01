#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, int r, int c)
{
	long long answer =0;
	int row=-1;//행(이차배열 첫번째)
	int col =0;//열(이차배열두번째)
	enum {Up, Down} dir;
	dir=Down;
	long long cnt=1;

	vector<vector<long long>> nums (n, vector<long long>(n, 0));

	long long total = pow(n, 2);
	while(cnt<=pow(n, 2))
	{
		bool flag=false;
		//오른쪽 끝 도달
		if (col == n - 1)
		{
			nums[++row][col] = cnt++;
			dir =Down;
			flag=true;
		}
		//아래쪽 끝
		if (row == n - 1)
		{
			nums[row][++col] = cnt++;
			dir = Up;
			flag = true;
		}
		//위쪽 끝
		if (row == 0)
		{
			nums[row][++col] = cnt++;
			dir = Down;
			flag = true;
		}
		//왼쪽 끝 도달
		if (col == 0)
		{
			nums[++row][col] = cnt++;
			dir = Up;
			flag = true;
		}
			
		if (dir == Up && col != n-1 && row !=0)
		{
			nums[--row][++col] = cnt++;
		}
		//그외 Down
		if (dir == Down && row != n - 1 && col != 0)
		{
			nums[++row][--col] = cnt++;
		}
	}
	answer = nums[r-1][c-1];

	return answer;
}

//int main()
//{
//	cout << solution(5, 3, 2);
//}