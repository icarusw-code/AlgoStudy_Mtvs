//#include <iostream>
//#include <vector>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//int main()
//{
//	
//	int testCase;
//	int clothesNum;
//	vector <pair<string, int>> clothes;
//
//	string s1, s2;
//	string buff;
//
//	cin >> testCase;
//	for (int i = 0; i < testCase; i++)
//	{
//		clothes.clear();
//		cin>> clothesNum;
//		for (int j = 0; j < clothesNum; j++)
//		{
//			cin >>s1>>s2;
//			if(clothes.empty())//ó������ ������ �׳� ����
//				clothes.push_back(make_pair(s2, 1));
//			else
//			{
//				bool flag=false;//���� ���� ���߿� ���;ȿ� �ش� cloth�� ������ true
//				auto it= (find(clothes.begin(), clothes.end(),s2 ));
//
//				/*for (int k = 0; k < clothes.size(); k++)
//				{
//					if (clothes[k].first == s2)
//					{
//						clothes[k].second++;
//						flag=true;
//						break;
//					}
//				}*/
//				if(it ==clothes.end())//������ ��� ������ش�
//					clothes.push_back(make_pair(s2, 1));
//				else
//					it->second++;
//
//				//Map���� �ٲ� ��
//			}
//			
//		}
//		int possibleClothes=1;
//		for (int k = 0; k < clothes.size(); k++)
//		{
//			possibleClothes *= (clothes[k].second+1);
//		}
//		cout << possibleClothes-1<<endl;
//	}	
//}