#include <iostream>

using namespace std;

// 트럭을 주차하는데 필요한 비용 계산하고 싶다.
// 한 대 주차 시 a 원, 두 대 주차 시 b 원, 세 대 주차 시 c 원
// 필요속성 : 주차요금, 총 비용
const int MAX = 101;
int parking[MAX]; // 주차장에 머무른 시간을 계산하기 위한 배열
int main()
{
    // 필요속성 : 주차요금, 총 비용
    int a, b, c, fare = 0;

    // 트럭을 주차하는데 필요한 비용 계산하고 싶다.
    // -> 각 트럭이 주차장에 머무른 시간에 따라 비용을 계산하고 싶다.
    // 1. 주차 요금을 입력 받는다.
    cin >> a >> b >> c;
    // 2. 트럭이 주차창에 도착한 시관과, 주차장을 떠난 시간을 입력받는다.
    for (int i = 0; i < 3; i++)
    {
        int arrive, depart;
        cin >> arrive >> depart;
        // 3. 트럭이 주차장에 머무른 시간을 계산한다.
        for (int j = arrive; j < depart; j++)
        {
            parking[j]++;
        }
    }

    // 4. 비용을 계산하고 싶다.
    for (int i = 1; i < MAX; i++)
    {
        switch (parking[i])
        {
        case 1:
            fare += parking[i] * a;
            break;
        case 2:
            fare += parking[i] * b;
            break;
        case 3:
            fare += parking[i] * c;
            break;
        default:
            break;
        }
    }
    cout << fare << endl;
    return 0;
}