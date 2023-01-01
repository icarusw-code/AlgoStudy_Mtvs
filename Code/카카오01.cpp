//#include <string>
//#include <vector>
//#include <map>
//#include <string>
//#include<algorithm>
//#include<iostream>
//
//using namespace std;
//
//vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
//   vector<int> answer;
//   map<char, int> map;
//
//   //map에 약관과 유효기간 넣기
//   for (int i = 0; i < terms.size(); i++)
//   {
//      map.insert({terms[i][0], stoi(terms[i].substr(2))});
//   }
//   //11번째가 약관, 0~10번째는 숫자, 0~3은 년도, 5~6은 달, 8~9는 일자
//   for (int i = 0; i < privacies.size(); i++)
//   {
//      //약관 숫자로 바꾸기
//      int year = stoi(privacies[i].substr(0, 4));
//      int month = stoi(privacies[i].substr(5, 2));
//      int day = stoi(privacies[i].substr(8,2));
//      //약관과 일치하는 유효기간 달에 더하기
//      month += map[privacies[i][11]];
//      //날짜에서 1빼기
//      day --;
//      if (day < 1)
//      {
//         month--;
//         day=28;
//      }
//      if (month > 12)
//      {
//         int quot = month / 12;
//         year +=quot;
//         month %= 12;
//      }
//      //비교하기
//      //privacies의 값이 today보다 크면 answer에 넣어준다
//      string tempM= to_string(month);
//      string tempD= to_string(day);
//      if (to_string(month).length() < 2)
//      {
//         tempM = "0"+to_string(month);
//      }
//      if (to_string(day).length() < 2)
//      {
//         tempD = "0" + to_string(day);
//      }
//      string temp= to_string(year)+ tempM+ tempD;
//      //.제거
//      today.erase(remove(today.begin(), today.end(), '.'), today.end());
//      //0이면 오늘까지 보관이므로 파기X
//      if ((stoi(today) - stoi(temp)) > 0)
//      {
//         answer.push_back(i+1);
//      }
//   }
//
//   return answer;
//}
//
