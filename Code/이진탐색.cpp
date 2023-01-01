#include <string>
#include <vector>
#include<iostream>
#include <algorithm>

using namespace std;

string ten_to_two(int tenNum, string twoNum)
{
   if (tenNum < 2)
   {
      twoNum += to_string(tenNum);
      return twoNum;
   }
   else
   {
      twoNum += to_string(tenNum%2);
      return ten_to_two(tenNum / 2, twoNum);
   }
}
vector<int> solution(string s) {
   vector<int> answer;
   int changeCount =0 ;
   int zeroCount = 0;

   while (s != "1")
   {
      changeCount ++;
      string temp = "";
      for (int i = 0; i < s.size(); ++i)
      {
         //0을 제거
         if (s[i] != '0')
         {
            temp += s[i];
         }
      }
      zeroCount += s.size() - temp.size();
      //길이를 이진변환
      int numLength = temp.size();
      string newNum = "";
      string str = ten_to_two(numLength, newNum);
      reverse(str.begin(), str.end());
      s=str;
      cout << s << endl;
   }
   answer.push_back(changeCount);
   answer.push_back(zeroCount);
   cout << changeCount <<endl;
   cout <<changeCount <<endl;
   return answer;

}

//int main()
//{
//   solution("110010101001");
//}