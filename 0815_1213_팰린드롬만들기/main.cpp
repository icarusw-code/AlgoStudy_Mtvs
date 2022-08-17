#include <iostream>
#include <algorithm>

using namespace std;

// 입력 받은 영어 이름을 팰린드롬으로 만들고 싶다.
// 필요속성 : 영어 이름, 알파벳 배열
string name;
int alphabet[26] = {0};

bool CanMakePalindrome(string);
void MakePalindrome(string);

int main()
{
    // 입력 받은 영어 이름을 팰린드롬으로 만들고 싶다.
    // 1. 영어 이름을 입력받는다.
    cin >> name;

    // 2. 팰린드롬을 만들고 싶다.
    // a. 팰린드롬을 만들 수 있다면 팰린드롬을 만들어 출력하고 싶다.
    if (CanMakePalindrome(name))
        MakePalindrome(name);
    // b. 가능하지 않다면 I'm Sorry Hansoo 를 출력한다.
    else
        cout << "I'm Sorry Hansoo";
}

// Palindrome Check
bool CanMakePalindrome(string s)
{
    // 1. 입력 받은 문자열의 개수를 카운팅 한다.
    for (int i = 0; i < s.length(); ++i)
    {
        ++alphabet[s[i] - 'A'];
    }

    // 2. 팰린드롬을 만들 수 없는 경우 걸러내기
    int count = 0;
    for (int i = 0; i < 26; ++i)
    {
        // -> 알파벳의 개수 중 홀수가 2개 이상이면 팰린드롬 불가
        if (alphabet[i] > 0 && alphabet[i] % 2 == 1)
        {
            ++count;
            if (count > 1)
                return false;
        }
    }
    return true;
}

// Palindrome 만들기
void MakePalindrome(string s)
{
    string answer = "";
    string temp = "";
    char center = ' ';
    for (int i = 0; i < 26; ++i)
    {
        if (alphabet[i] > 0)
        {
            // 1. 이름의 길이가 짝수라면 알파벳 절반의 개수만큼만 앞으로 붙이고, 절반의 개수만큼 뒤에 붙인다.
            // -> 절반 만큼 그냥 더해준다.
            for (int j = 0; j < alphabet[i] / 2; ++j)
            {
                answer += i + 'A';
                temp += i + 'A';
            }
            // 2. 이름의 길이가 홀수라면 해당 문자를 기억한다.
            if (alphabet[i] % 2 != 0)
            {
                center = i + 'A';
            }
        }
    }
    // 3. 임시 저장한 배열을 뒤집는다.
    reverse(temp.begin(), temp.end());
    // 4. center 에 저장된 값이 있으면 더해준다
    // -> 이름의 길이가 홀수라면 가운데 값을 더한다.
    if (center != ' ')
    {    
        answer += center;
    }
    // 5. 뒤집은 배열을 더해준다.
    answer += temp;
    cout << answer;
}