#include <iostream>
#include <vector>

using namespace std;
// N 일 동안의 온도를 입력받아 K 일 씩 묶어서 K 일의 온도의 합이 최대가 되는 값을 출력하고 싶다.
// 필요속성 : 전체 날짜 수, 연속 날짜 수, 최댓값, 온도배열

int MAX(int a, int b) { return (a > b) ? a : b; }

int main()
{
	// 필요속성 : 전체 날짜 수, 연속 날짜 수, 최댓값, 온도배열
	int n, k, max = INT_MIN, sum = 0;
	vector<int> temperature;
	// 1. 입력 받기
	// a. 전체 날짜 수, 연속 날짜 수 입력 받기
	cin >> n >> k;
	// b. 온도 입력 받기
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		temperature.push_back(temp);
	}

	// 2. K 일 씩 묶어서 온도의 합 구하기
	// -> K 일 씩 묶은 온도에서 다음 index 의 data 를 더해주고 기존 index data 를 빼준다
	//	ex) 1 + 2 + 3 >> 1 + 2 + 3 + 4 - 1 == 2 + 3 + 4
	// a. 첫 묶음은 0 ~ K 까지
	for (int i = 0; i < k; i++)
	{
		sum += temperature[i];
	}
	// b. 첫 묶음과 max 를 비교하고 저장
	max = MAX(max, sum);
	// c. 첫 묶음과 다음 묶음을 계산
	for (int i = 0; i < n - k; i++)
	{
		sum = sum + temperature[k + i] - temperature[i];
		max = MAX(max, sum);
	}

	// [시간초과] : n 과 k 값이 크면 반복문의 횟수가 너무 커짐
	//for (int i = 0; i < n - k + 1; i++)
	//{
	//	int sum = 0;
	//	for (int j = i; j < k + i; j++)
	//	{
	//		sum += temperature[j];
	//	}
	//	max = MAX(sum, max);
	//}

	// 3. 최대값 출력
	cout << max;
}