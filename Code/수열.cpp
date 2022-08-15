//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//int main()
//{
//	int totalDay;
//	int sumDay;
//	vector<int> temperature;
//	int maxSum=0;
//	int temp=0;
//
//
//	cin >> totalDay;
//	cin >> sumDay;
//
//	for (int i = 0; i < totalDay; ++i)
//	{
//		int n;
//		cin >> n;
//		temperature.push_back(n);
//
//		//처음 묶음만 더하기
//		if (i < sumDay)
//		{
//			temp +=temperature[i];
//			maxSum=temp;
//		}
//
//		//처음묶음을 지나면 차이만큼 더하기
//		else
//		{
//			temp += (temperature[i] - temperature[i - sumDay]);
//			if(temp> maxSum)
//				maxSum=temp;
//		}
//	}
//	
//	cout << maxSum;
//	return 0;
//}


//시간초과

//int main()
//{
//	int totalDay;
//	int sumDay;
//	vector<int> temperature;
//	int maxTemp=-999999999;
//
//	cin >> totalDay;
//	cin >> sumDay;
//
//	for (int i = 0; i < totalDay; ++i)
//	{
//		int n;
//		cin >>n;
//		temperature.push_back(n);
//	}
//	for (int j = 0; j < totalDay - sumDay + 1; ++j)
//	{
//		int sum=0;
//		for (int k = j; k < j + sumDay; ++k)
//		{
//			sum +=temperature[k];
//		}
//		if(sum > maxTemp)
//			maxTemp=sum;
//	}
//	cout << maxTemp;
//	return 0;
//}