//#include <iostream>
//#include <vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	//���� ū ����� ���� ����� �۾ƾ� �Ѵ�
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
//	//�������� ����
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