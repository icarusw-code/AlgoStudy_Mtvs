//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int countryNum=0;
//	long long priceSum=0;
//	vector<long long> prices;
//	vector<long long> distances;
//	int price, distance, minValue;
//
//	cin >> countryNum;
//	//��� ���ÿ��� �⸧�� �ּ������� �ִ´�
//	//������ ������ ���� ������ ��ǻ� �����Ѵ�
//	for (int i = 0; i < countryNum-1; ++i)
//	{
//		cin >> distance;
//		distances.push_back(distance);
//	}
//	for (int i = 0; i < countryNum - 1; ++i)
//	{
//		cin >> price;
//		prices.push_back(price);
//	}
//	minValue= prices[0];
//	//�⸧�� �� �� �������ñ��� ���������� �Ÿ���ŭ �⸧�� �����Ѵ�
//	for (int j = 0; j < prices.size(); j++)
//	{		
//		if(minValue > prices[j])
//			minValue=prices[j];
//		priceSum += distances[j] * minValue;
//	}
//
//	cout << priceSum;
//
//	return 0;
//}