#include <iostream>
#include <cstring>
#include <map>

int main()
{
	int i;
	std::map<std::string, int> name_map;
	std::map<int, std::string> index_map;
	
	int pokedex_length, problem_length;

	std::cin >> pokedex_length;
	std::cin >> problem_length;

	std::string input;
    
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    
	for (i = 0; i < pokedex_length; i++)
	{
		std::cin >> input;
		name_map[input] = i;
		index_map[i] = input;
	}

	for (i = 0; i < problem_length; i++)
	{
		std::cin >> input;

		if (47 < input[0] && input[0] < 58)
		{
			std::cout << index_map[std::stoi(input) - 1] << '\n';
		}
		else
		{
			std::cout << name_map[input]+1 << '\n';
		}
	}

	return 0;
}