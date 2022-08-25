#include <iostream>
#include <cstring>

int main()
{
	std::string input;
	int alphabet[26]{};
	char forward[50];
	int word_length;
	int index = 0;
	int mid = -1;
	
	std::cin >> input;
	word_length = input.length();

	for (int i = 0; i < word_length; i++)
	{
		alphabet[input[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] % 2 == 1)
		{
			if (mid == -1)
			{
				mid = i;
			}
			else
			{
				std::cout << "I'm Sorry Hansoo\n";
				return 0;
			}
		}
		
		for (int j = 0; j< alphabet[i] / 2; j++)
		{
			forward[index++] = (char)('A' + i);
		}
	}

	if (mid != -1)
	{
		forward[index] = ('A' + mid);
	}
	
	for (int i = 0; i < index; i++)
	{
		forward[word_length - i - 1] = forward[i];
	}
	forward[word_length] = '\0';
	
	std::cout << forward << "\n";
	
	return 0;
}