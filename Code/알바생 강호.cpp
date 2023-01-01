//#include <iostream>
//#include <vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	//팁이 큰 사람은 받은 등수가 작아야 한다
//	vector<int> tips;
//	int n;
//	int finalTip;
//	long long sumTip=0;
//
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int tip;
//		cin >> tip;
//		tips.push_back(tip);
//	}
//
//	//오름차순 정렬
//	sort(tips.begin(), tips.end(), greater<>());
//
//	for (int i = 0; i < n; i++)
//	{
//		finalTip = tips[i] - (i + 1 - 1);
//		if(finalTip<0) finalTip=0;
//		sumTip += finalTip;
//	}
//
//	cout << sumTip;
//
//	return 0;
//	
//}