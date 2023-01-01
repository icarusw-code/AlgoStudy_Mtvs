#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int N, vector<vector<int>> simulation_data)
{
	int answer = 0;
	//초기화
	vector<vector<bool>> nSchedule (N, vector<bool>(10001, false));

	for (int i = 0; i < simulation_data.size(); ++i)
	{
		bool isAssigned=false;
		int startTime = simulation_data[i][0];
		int endTime = simulation_data[i][0]+ simulation_data[i][1];

		while (!isAssigned)
		{
			//창구 탐색
			for (int j = 0; j < nSchedule.size(); ++j)
			{
				//스케줄링이 비었으면
				if (nSchedule[j][startTime] == false)
				{
					//할당하기
					for (int k = startTime; k <endTime; ++k)
					{
						nSchedule[j][k] = true;
					}
					isAssigned = true;
					break;
				}
			}
			//만약 모든 스케줄러가 꽉차서 할당받지 못했으면
			//대기
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