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
//	//비싼 도시에서 기름을 최소한으로 넣는다
//	//마지막 도시의 주유 가격은 사실상 무시한다
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
//	//기름이 더 싼 다음도시까지 갈때까지의 거리만큼 기름을 충전한다
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