#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, int r, int c)
{
	long long answer =0;
	int row=-1;//��(�����迭 ù��°)
	int col =0;//��(�����迭�ι�°)
	enum {Up, Down} dir;
	dir=Down;
	long long cnt=1;

	vector<vector<long long>> nums (n, vector<long long>(n, 0));

	long long total = pow(n, 2);
	while(cnt<=pow(n, 2))
	{
		bool flag=false;
		//������ �� ����
		if (col == n - 1)
		{
			nums[++row][col] = cnt++;
			dir =Down;
			flag=true;
		}
		//�Ʒ��� ��
		if (row == n - 1)
		{
			nums[row][++col] = cnt++;
			dir = Up;
			flag = true;
		}
		//���� ��
		if (row == 0)
		{
			nums[row][++col] = cnt++;
			dir = Down;
			flag = true;
		}
		//���� �� ����
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
		//�׿� Down
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