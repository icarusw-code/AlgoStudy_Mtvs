#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*/
int main()
{
	int a, b, c=0;
	int truck[3][2];
	int truckCount=0;
	vector <pair<int, int>> truckData;
	
	cin >>a >> b >> c;

	for (int i = 0; i < 3; i++)
	{
			cin >> truck[i][0]>> truck[i][1];
	}
	for (int i = 0; i < 6; i++)
	{
		
		cin >> truckData[i].first;
		if (i % 2 == 0)//들어온차
			truckData[i].second=1;
		else
			truckData[i].second=-1;

		//정렬
		sort(truckData.begin(), truckData.end());

		for (int i = 0; i < truckData.size()-1; i++)
		{
			truckCount += truckData[i].second;
			//truckData[i].first
		}
	}
}
*/