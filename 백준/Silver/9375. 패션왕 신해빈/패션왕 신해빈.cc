#include <iostream>
#include <cstring>
#include <functional>
#include <map>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int case_length, clothes_length;
	std::string clothes_type, clothes_name;
	std::map<std::string, int> clothes_map;
	int i, j, res;
	
	std::cin >> case_length;

	for (i = 0; i < case_length; i++)
	{
		std::cin >> clothes_length;

		for (j = 0; j < clothes_length; j++)
		{
			std::cin >> clothes_name;
			std::cin >> clothes_type;

			if (clothes_map.find(clothes_type) != clothes_map.end())
			{
				clothes_map[clothes_type]++;
			}
			else
			{
				clothes_map[clothes_type] = 1;
			}
		}
		
		res = 1;
		for (auto it = clothes_map.begin(); it != clothes_map.end(); it++)
		{
			res *= (it->second + 1);
		}
		
        std::cout << res - 1 << "\n";
		clothes_map.clear();
	}
	
	return 0;
}