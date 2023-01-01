#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int N, vector<vector<int>> simulation_data)
{
	int answer = 0;
	//�ʱ�ȭ
	vector<vector<bool>> nSchedule (N, vector<bool>(10001, false));

	for (int i = 0; i < simulation_data.size(); ++i)
	{
		bool isAssigned=false;
		int startTime = simulation_data[i][0];
		int endTime = simulation_data[i][0]+ simulation_data[i][1];

		while (!isAssigned)
		{
			//â�� Ž��
			for (int j = 0; j < nSchedule.size(); ++j)
			{
				//�����ٸ��� �������
				if (nSchedule[j][startTime] == false)
				{
					//�Ҵ��ϱ�
					for (int k = startTime; k <endTime; ++k)
					{
						nSchedule[j][k] = true;
					}
					isAssigned = true;
					break;
				}
			}
			//���� ��� �����ٷ��� ������ �Ҵ���� ��������
			//���
			if (!isAssigned)
			{
				startTime++;
				endTime++;
				answer++;
			}
		}
	}
	return answer;
}
//int main()
//{
//	cout << solution(2, {{0,3}, {2,5},{4,2},{5,3}} );
//}