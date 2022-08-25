#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int length, require, count = 0;
	int *materials;
	int *max, *min;

	std::cin >> length;
	std::cin >> require;

	// 재료들 입력
	materials = new int[length];
	for (int i = 0; i < length; i++)
		std::cin >> materials[i];

	// 재료 정렬
	std::sort(materials, materials + length);

	// 앞뒤로 포인터 생성
	min = materials;
	max = materials + length - 1;
	
	// 포인터가 서로 교차되면 종료
	while (min < max)
	{
		// 요구 값과 일치하면 카운트하고 양쪽 포인터 이동
		if (*min + *max == require)
		{
			count++;
			min++;
			max--;
		}
		else if (*min + *max < require)
			min++;
		else
			max--;
	}

	std::cout << count;

	return 0;
}