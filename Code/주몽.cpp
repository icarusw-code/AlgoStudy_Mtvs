//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////시간초과
//int main()
//{
//
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int answer=0;
//	int count;
//	int needNum;
//	vector<int> nums;
//	cin >> count;
//	cin >> needNum;
//	vector<int> bitMask(count-2, 0);//두개 1 
//	bitMask.push_back(1);
//	bitMask.push_back(1);
//
//
//	//입력받기
//	for (int i = 0; i < count; i++)
//	{
//		int n;
//		cin >> n;
//		nums.push_back(n);
//	}
//	sort(nums.begin(), nums.end());
//
//	//비트마스킹 돌려주기
//	do
//	{
//		//find 시간 초과
//		auto firstIt= find(bitMask.begin(), bitMask.end(), 1);//O(n)
//		auto secondIt= find(firstIt+1, bitMask.end(), 1);
//
//		int firstN= distance(bitMask.begin(), firstIt);
//		int secondN = distance(bitMask.begin(), secondIt);
//
//		if ((nums[firstN] + nums[secondN]) == needNum)
//		{
//			answer++;
//		}
//
//	}while(next_permutation(bitMask.begin(), bitMask.end()));//O(n)
//
//	// => n 제곱
//	
//	cout << answer;
//
//	return 0;
//}