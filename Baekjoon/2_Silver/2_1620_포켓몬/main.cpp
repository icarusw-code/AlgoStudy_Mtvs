#include <iostream>
#include <map>
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
	map<int, string> poketmon_name;
	map<string, int> poketmon_number;
	vector<string> answer;
	// 포켓몬 도감에 등록된 번호와 포켓몬의 이름을 매칭시켜주고 싶다.
	// 0. 도감에 등록된 포켓몬 수, 풀어야할 문제 수를 입력받는다.
	cin >> n >> m;
	// 1. 포켓몬 도감에 정보를 입력하고 싶다.
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
        //poketmon_name.inser(make_pair(i + 1, name));
		poketmon_name.insert(pair<int, string>(i + 1, name));
		poketmon_number.insert(pair<string, int>(name, i + 1));
	}
	// 2. 도감의 정보와 문제를 매칭하고 싶다.
	for (int i = 0; i < m; i++)
	{
		// a. 번호 or 포켓몬의 이름을 입력받는다.
		string info;
		cin >> info;
		// b. info 에 숫자(번호)가 들어왔는지 판별한다.
		if (isdigit(info[0]))
		{
			// stoi : 문자열을 int 형으로 바꿔주는 함수
			// c. 해당 key 의 포켓몬 이름을 저장한다.
			answer.push_back(poketmon_name[stoi(info)]);
		}
		// d. info 에 이름이 들어왔다면
		else
		{
			// e. 해당 이름의 포켓몬 번호를 저장한다.
			answer.push_back(to_string(poketmon_number[info]));
		}
	}
	// 3. 결과를 출력한다.
	for (vector<string>::iterator iter = answer.begin(); iter != answer.end(); iter++)
	{
		cout << *iter << '\n';
	}
}
// endl 의 경우 flush() 함수를 겸하기 때문에 실행마다 출력 버퍼를 지워주는 과정이 생겨 '\n' 보다 속도가 느리다.