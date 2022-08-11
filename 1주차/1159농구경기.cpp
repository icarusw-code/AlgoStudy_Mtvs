#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//같은 성 4명 이하인가
	int N;
	cin >> N;
	string players[150];
	int result[150] = {0, };
	for (int i = 0; i < N; i++) {
		cin >> players[i]; // N번 입력 받아서 배열에 넣기
	}
	for (int i = 0; i < N; i++) {
		//result배열에 +1한다,
		//i 번째 string원소의 char형인 첫 글자를 int를 바꿔 그에 해당하는 인덱스의 값을
		result[players[i][0] - 'a']++;
	}
	//int 0 은 0 char 0 은 48, char a는 97
	//result에서 5이상인 원소를 알파벳으로 바꿔서 출력
	int cnt = 0;
	for (int i = 0; i < 150; i++) {
		if (result[i] >= 5) {
			cout << char(i +97);
			cnt++;
		}
		if (i == 149 && result[i] == 0 && cnt == 0) //마지막 까지 모두 0이면
			cout << "PREDAJA";
	}
		
}