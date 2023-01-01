#include <string>
#include <vector>
#include<iostream>

using namespace std;

void DFS(vector<int> numbers, int target, int index, bool plus, int* answer)
{
   if (numbers.size() == index)
   {
      int sum = 0;
      string temp = "";
      for (int i = 0; i < numbers.size(); ++i)
      {
         sum += numbers[i];
         temp += to_string(numbers[i]);
      }
      if (sum == target)
      {
         *answer += 1;
         cout << temp << endl;
      }
      return;
   }
   else
   {
      //부호 바꾸기
      if (!plus)
      {
         numbers[index] = -numbers[index];
      }

      //양수
      DFS(numbers, target, index + 1, true, answer);
      //음수
      DFS(numbers, target, index + 1, false, answer);
   }
}
int solution(vector<int> numbers, int target) {
   int answer = 0;
   DFS(numbers, target, 0, true, &answer);
   //DFS(numbers, target, 0, false, &answer);

   return answer;
}
int main()
{
   solution({1, 1, 1,1,1},3);
}

/*
#include <string>
#include <vector>

using namespace std;
int answer = 0;

void DFS(vector<int>numbers, int target, int sum, int count) {
   if (numbers.size() == count) {//끝까지 탐색했고
      if (sum == target)//값이 일치하면
         answer++;//경우의 수+1
      return;
   }
   DFS(numbers, target, sum - numbers[count], count + 1);
   DFS(numbers, target, sum + numbers[count], count + 1);

}
int solution(vector<int> numbers, int target) {
   DFS(numbers, target, 0, 0);
   return answer;
}*/