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
//			if(clothes.empty())//처음으로 들어오면 그냥 저장
//				clothes.push_back(make_pair(s2, 1));
//			else
//			{
//				bool flag=false;//벡터 도는 와중에 벡터안에 해당 cloth가 있으면 true
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
//				if(it ==clothes.end())//없으면 페어 만들어준다
//					clothes.push_back(make_pair(s2, 1));
//				else
//					it->second++;
//
//				//Map으로 바꿀 것
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