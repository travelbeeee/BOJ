/*
	dp[i] := i�� ° ���� �ش� �������� �������� �� ���� �� �ִ� �ִ� ����
	--> dp[i]�� �ش� �������� �����ؼ� ��� ���� + �ش� �������� �����ϰ� �� ������ �������� �ִ� ���� �� �ȴ�.
	:= schedule[i][1] + max(dp[i + schedule[i][0]] ~ dp[N]);
	
*/

#include<iostream>
#include<algorithm>

using namespace std;

int N;
int schedule[2][15];
int dp[15];

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> schedule[0][i] >> schedule[1][i];
	for (int i = N - 1; i >= 0; i--) {
		if (i + schedule[0][i] > N) { // i + 1 �� ° �� ��㿡 �ɸ��� �ð��� ��� ������ ���� �� �������� ������ ���Ѵ�.
			dp[i] = 0;
			continue;
		}
		int m = 0;
		for (int j = i + schedule[0][i]; j < N; j++)
			m = max(m, dp[j]);
		dp[i] = m + schedule[1][i];
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans = max(ans, dp[i]);
	cout << ans;
}