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
//   //map�� ����� ��ȿ�Ⱓ �ֱ�
//   for (int i = 0; i < terms.size(); i++)
//   {
//      map.insert({terms[i][0], stoi(terms[i].substr(2))});
//   }
//   //11��°�� ���, 0~10��°�� ����, 0~3�� �⵵, 5~6�� ��, 8~9�� ����
//   for (int i = 0; i < privacies.size(); i++)
//   {
//      //��� ���ڷ� �ٲٱ�
//      int year = stoi(privacies[i].substr(0, 4));
//      int month = stoi(privacies[i].substr(5, 2));
//      int day = stoi(privacies[i].substr(8,2));
//      //����� ��ġ�ϴ� ��ȿ�Ⱓ �޿� ���ϱ�
//      month += map[privacies[i][11]];
//      //��¥���� 1����
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
//      //���ϱ�
//      //privacies�� ���� today���� ũ�� answer�� �־��ش�
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
//      //.����
//      today.erase(remove(today.begin(), today.end(), '.'), today.end());
//      //0�̸� ���ñ��� �����̹Ƿ� �ı�X
//      if ((stoi(today) - stoi(temp)) > 0)
//      {
//         answer.push_back(i+1);
//      }
//   }
//
//   return answer;
//}
//
