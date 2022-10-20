#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 포켓몬 도감에 등록된 번호와 포켓몬의 이름을 매칭시켜주고 싶다.
// 필요속성 : 도감에 등록된 포켓몬 수, 풀어야할 문제 수, 포켓몬 도감 정보
int main()
{
	// 필요속성 : 도감에 등록된 포켓몬 수, 풀어야할 문제 수, 포켓몬 도감 정보
	int n, m;
	vector<string> poketmon;
	vector<string> answer;
	
	// 포켓몬 도감에 등록된 번호와 포켓몬의 이름을 매칭시켜주고 싶다.
	// 0. 도감에 등록된 포켓몬 수, 풀어야할 문제 수를 입력받는다.
	cin >> n >> m;
	// 1. 포켓몬 도감에 정보를 입력하고 싶다.
	poketmon.push_back("START");
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		poketmon.push_back(name);
	}
	// 2. 도감의 정보와 문제를 매칭하고 싶다.
	for (int i = 0; i < m; i++)
	{
		// a. 번호 or 포켓몬의 이름을 입력받는다.
		string temp;
		cin >> temp;
		// b. temp 에 숫자(번호)가 들어왔는지 판별한다.
		if (isdigit(temp[0]))
		{
			// stoi : 문자열을 int 형으로 바꿔주는 함수
			// c. 번호가 들어왔으면 해당 인덱스의 포켓몬 이름을 저장한다.
			answer.push_back(poketmon.at(stoi(temp)));
		}
		// d. temp 에 이름이 들어왔다면
		else
		{
			// e. 해당 이름의 도감에서 찾는다.
			// find 가 시간초과 >> 이분탐색이나 map 을 이용?
			vector<string>::iterator iter = find(poketmon.begin(), poketmon.end(), temp);
			// f. 찾은 도감의 index 를 저장한다.
			int index = distance(poketmon.begin(), iter);
			answer.push_back(to_string(index));
		}
	}
	
	// 3. 결과를 출력하고 싶다.
	for (vector<string>::iterator iter = answer.begin(); iter != answer.end(); iter++)
	{
		cout << *iter << endl;
	}
}
/*
error: no matching function for call to ‘find(std::vector<std::__cxx11::basic_string<char> >::iterator, std::vector<std::__cxx11::basic_string<char> >::iterator, std::string&)’
*/