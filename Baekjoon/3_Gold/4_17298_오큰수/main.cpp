#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> sequence, answer;
stack<int> st;

void Input()
{
	cin >> N;

	sequence.assign(N, 0);
	answer.assign(N, -1);

	for (int i = 0; i < N; ++i)
		cin >> sequence[i];
}

void NGE(int idx)
{
	// 오큰수를 구하고 싶다.
	// 1. 스택이 비어있지 않다면
	if (!st.empty())
	{
		// a. 현재 index 수열을 스택의 top 과 크기를 비교한다.
		// -> 현재 수열 값이 top 보다 크거나 같으면 반복
		while (sequence[idx] >= st.top())
		{
			// b. 스택 pop
			st.pop();
			// c. pop 하다가 스택이 비었다면 break;
			if (st.empty()) break;
		}
		// 2. 해당 index 의 오큰수를 answer 에 저장한다.
		if(!st.empty()) answer[idx] = st.top();
	}
	// 3. 스택에 현재 수열을 push 한다.
	st.push(sequence[idx]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// 1. 입력
	Input();

	// 2. 인덱스를 뒤에서 부터 탐색
	for (int i = N - 1; i >= 0; --i)
		NGE(i);

	// 3. 결과 출력
	for (vector<int>::iterator it = answer.begin(); it != answer.end(); ++it)
		cout << *it << ' ';
}