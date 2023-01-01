#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
   int answer = 0;
   vector<int> hamburger;
   if (ingredient.size() < 4) return answer;
   for (int i = 0; i < ingredient.size(); i++)
   {
      hamburger.push_back(ingredient[i]);
      bool canMake = true;

      while (canMake && hamburger.size() >= 4)
      {
         canMake = false;
         if (hamburger[hamburger.size() - 4] == 1 && hamburger[hamburger.size() - 3] == 2 && hamburger[hamburger.size() - 2] == 3 && hamburger[hamburger.size()-1] == 1)
         {
            answer++;
            for (int j = 0; j < 4; ++j)
            {
               hamburger.erase(hamburger.begin() + hamburger.size() - 1);
            }
            canMake = true;
         }

      }
   }
   return answer;
}