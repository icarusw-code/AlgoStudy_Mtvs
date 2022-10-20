#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, score[3], winningTime[3];
int currTime, drawTime; // 이기는 시점의 시간, 동점이 된 시점의 시간
int winningTeam = -1;   // 이기는 팀 flag
string answer[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// 1. 입력 받기
	cin >> N;

	vector<pair<int, string>> record(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> record[i].first >> record[i].second;

		// 2. 득점한 팀 확인
		if (record[i].first == 1)	++score[1];
		else if (record[i].first == 2)	++score[2];

		// 3. 점수 비교
		if (score[1] > score[2])
		{
			// a. 비기던 중이였다면 현재 시간을 저장
			if (winningTeam < 0)	currTime = stoi(record[i].second.substr(0, 2)) * 60 + stoi(record[i].second.substr(3));
			winningTeam = 1;
		}
		else if (score[1] < score[2])
		{
			// a. 비기던 중이였다면 현재 시간을 저장
			if (winningTeam < 0)	currTime = stoi(record[i].second.substr(0, 2)) * 60 + stoi(record[i].second.substr(3));
			winningTeam = 2;
		}
		// 4. 동점이 되었다면 시간을 누적한다.
        // -> 이기고 있던 시간 = 동점이 된 시점 - 이기던 시점
		else
		{
			// a. 동점이 된 시간을 계산한다.
			drawTime = stoi(record[i].second.substr(0, 2)) * 60 + stoi(record[i].second.substr(3));
			// b. 이기고 있던 팀의 시간 누적
			if (winningTeam == 1)	winningTime[1] += drawTime - currTime;
			else if (winningTeam == 2)	winningTime[2] += drawTime - currTime;
			winningTeam = -1;
		}
		// 5. 마지막 득점이라면
		if (i == N - 1)
		{
			// a. 이기고 있던 팀의 시간 누적
			if (winningTeam == 1)	winningTime[1] += 48 * 60 - currTime;
			else if (winningTeam == 2)	winningTime[2] += 48 * 60 - currTime;
		}
	}

	// 6. 결과 변환 및 출력
	for (int i = 1; i < 3; ++i)
	{
		// a. 이긴 시간의 Minute 이 10 보다 작다면 0 을 붙인다
		if (winningTime[i] / 60 < 10)	answer[i] += '0';
		answer[i] += to_string(winningTime[i] / 60);
		answer[i] += ':';
		// b. 이긴 시간의 Second 가 10보다 작다면 0 을 붙인다
		if (winningTime[i] % 60 < 10)	answer[i] += '0';
		answer[i] += to_string(winningTime[i] % 60);

		cout << answer[i] << '\n';
	}
}