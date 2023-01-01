#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
   long long answer = -1;//distance
   int deliverBox=0;
   int pickUpBox = 0;

   //가져갈 상자(가면서 다 줄것)
   for (int i = deliveries.size()-1; i>=0; i--)
   {
      if(deliveries[i]==0 || pickups[i] == 0) continue;

      long
      deliverBox += deliveries[i];
      pickUpBox += pickups[i];
      deliveries[i]=0;
      if (deliverBox > cap)
      {
         deliverBox = cap;
         deliveries[i] = deliverBox-cap;
      }
      break;
   }
   return answer;
}