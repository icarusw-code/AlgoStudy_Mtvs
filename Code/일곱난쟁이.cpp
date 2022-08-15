//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//   int all[9];
//   int sum = 0;
//   int num1=0;
//   int num2=0;
//
//   for (int i = 0; i < 9; i++)
//   {
//      cin >> all[i];
//      sum += all[i];
//   }
//   int sub = sum - 100;
//
//   //정렬
//   for (int i = 0; i < 9; i++)
//   {
//      for (int j = 0; j < 8-i; j++)
//      {
//         //바꾸기
//         if (all[j] > all[j+1])
//         {
//            int temp = all[j];
//            all[j] = all[j+1];
//            all[j+1] = temp;
//         }
//      }
//   }
//
//   //합이 sum -100 되는 두 값
//   for (int a = 0; a < 9; a++)
//   {
//      for (int b = 0; b < 9; b++)
//      {
//         if (all[a] + all[b] == sub)
//         {
//            num1 = all[a];
//            num2 =all[b];
//            break;
//         }
//      }
//   }
//   //출력
//   for (int k = 0; k < 9; k++)
//   {
//      if(!(all[k] == num1 || all[k] == num2))
//         cout << all[k] << endl;
//   }
//   return 0;
//}