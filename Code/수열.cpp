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
//		//ó�� ������ ���ϱ�
//		if (i < sumDay)
//		{
//			temp +=temperature[i];
//			maxSum=temp;
//		}
//
//		//ó�������� ������ ���̸�ŭ ���ϱ�
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


//�ð��ʰ�

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