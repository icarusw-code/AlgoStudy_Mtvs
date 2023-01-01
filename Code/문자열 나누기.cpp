#include <string>
#include <vector>

using namespace std;

int solution(string s) {
   int answer = 0;

   while (s.length() > 0)
   {
      int sameCount = 1;
      int otherCount = 0;
      for (int i = 1; i < s.length(); ++i)
      {
         if (s[i] == s[0])
         {
            sameCount++;
         }
         else
         {
            otherCount++;
         }
         if (sameCount == otherCount)
         {
            s=s.substr(i+1);
            answer++;
            break;
         }
      }
      if (sameCount != otherCount)
      {
         answer++;
         break;
      }

   }
   return answer;
}