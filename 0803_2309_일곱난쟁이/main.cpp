#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

// 9명의 난쟁이 중 난쟁이가 아닌 구라쟁이 걸러내기
// 원래 난쟁이들의 키 총 합은 100
// 필요속성 : 난쟁이들의 키, 총 합
int main()
{
    // 필요속성 : 난쟁이들의 키, 총 합
    int height[9];
    int sum = 0;
    int i, j;
    // 난쟁이들의 키를 입력 받는다.
    for (int i = 0; i < MAX; i++)
    {
        cin >> height[i];
        sum += height[i];
    }
    sort(height, height + MAX);
    // 구라쟁이 걸러내기
    for (i = 0; i < MAX - 1; i++)
    {
        for (j = i + 1; j < MAX; j++)
        {
            if (sum - (height[i] + height[j]) == 100)
            {
                // -> 난쟁이들의 키 총합에서 두 명의 난쟁이의 키를 뺀 값이 100이면 그 두 명이 구라쟁이
                break;
            }
        }
    }
    // 구라쟁이 빼고 출력
    for (int k = 0; k < MAX; k++)
    {
        if (k != i && k != j)
        {
            cout << height[k] << endl;
        }
    }
    return 0;
}
