//#include<iostream>
//#include<string>
//using namespace std;
//
//int N, team, winnerTeam;
//int scoreA, scoreB;
//string scoredTime, lastTime="00:00";//이전시간
//int timeA, timeB;
//
////시간 차이 구하기
//int StoTime(string timeA, string timeB)
//{
//	int time;
//	int minA = stoi(timeA.substr(0,2));
//	int secA = stoi(timeA.substr(3, 2));
//	int minB = stoi(timeB.substr(0, 2));
//	int secB = stoi(timeB.substr(3, 2));
//
//	time = (minA*60 +secA)-(minB*60 +secB);
//	return time;
//}
//
//string TimeToS(int time)
//{
//	string min = to_string(time / 60);
//	string sec = to_string(time % 60);
//	if (sec.length() < 2)
//	{
//		sec= "0"+sec;
//	}
//	if (min.length() < 2)
//	{
//		min = "0" + min;
//	}
//	return min+":"+sec;
//}
//int main()
//{
//	//1,2팀의 점수를 비교해야 함
//	//시간을 측정해야 함
//	cin >> N;
//	for(int i=0; i<N; i++)
//	{
//		cin >> team >> scoredTime;
//
//		if (scoreA > scoreB )
//		{
//			timeA += StoTime(scoredTime,lastTime);
//		}
//		else if(scoreA < scoreB )
//		{
//			timeB += StoTime(scoredTime, lastTime);
//		}
//	
//		lastTime = scoredTime; 
//		if (team == 1)
//			scoreA++;
//		if (team == 2)
//			scoreB++;
//	}
//
//	if (scoreA > scoreB)
//		timeA += StoTime("48:00", lastTime);
//	else if (scoreA < scoreB)
//		timeB += StoTime("48:00", lastTime);
//
//
//	std::cout << TimeToS(timeA)<<'\n';
//	std::cout << TimeToS(timeB);
//
//	return 0;
//}