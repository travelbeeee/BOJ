/*
	BOJ 1459 �ȱ⹮��
	����1�� + ����1�� == �밢��1��
	����2�� == ����2�� == �밢��2�� �̹Ƿ� 
	�밢��, ����/���� �̵� cost�� ���ؼ� �����δ�!
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long X, Y, W, S;
	cin >> X >> Y >> W >> S;

	// ������2�� = ����2�� = �밢��2��
	// ������1�� ����1�� = �밢��1��
	// --> 2 * W �� S�� ���ϰ� 2 * W �� 2 * S �� ���غ���.
	if (2 * W < S) { // ���ص� �밢���� ����
		cout << (X + Y) * W;
	}
	else if (2 * W < 2 * S) {
		cout << min(X, Y) * S + ((X + Y) - 2 * min(X, Y)) * W;
	}
	else { // 2 * S <= 2 * W --> �밢������ �̵��ϴ°� ������ ����! �밢������ �ִ��� �̵��ϰ� ¦����ŭ�̵��ϰ� ���� Ȧ���� W�� �̵�!
		cout << min(X, Y) * S + ((Y - min(X, Y)) / 2) * (2 * S) + ((Y - min(X, Y)) % 2) * W + ((X - min(X, Y)) / 2) * (2 * S) + ((X - min(X, Y)) % 2) * W;
	}
	return 0;
}