#include <iostream>
#include <string>

using namespace std;

// 소문자로 주어진 단어 S 에서 각 알파벳이 몇 개가 포함되었는지 출력
// 필요속성 : 단어, 알파벳 배열
int main()
{
    // 필요속성 : 단어, 알파벳 카운팅 배열
    string s;
    int alphabet[26] = {0};
    // 1. 단어 S 를 입력받는다.
    cin >> s;
   
    // 2. 각 알파벳이 몇 개가 포함되었는지 계산한다.
    // -> s 의 길이만큼 반복문을 돌려 카운팅
    for(int i=0; i<s.length(); i++) {
        alphabet[s[i] - 'a']++;
    }

    //3 . 계산한 결과를 출력한다.
    for(int i=0; i<26; i++) {
        cout << alphabet[i] << ' ';
    }

    return 0;
}