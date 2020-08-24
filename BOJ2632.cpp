/*
	������ ������ �ִ� 1000���̰�, ���� ������ �ִ� ũ�⵵ 1000�̹Ƿ�
	��� ���ӵ� ���� ������ ���� ���ϴ� O(N^2) �˰����� ����ص� ������,
	�ִ� ���� ������ �� ũ�⵵ 1000 * 1000 �ۿ� �ȵǹǷ�
	��� ���ӵ� ���� ������ ���� �� ���ؼ� count�� �����س��� �� �ִ�.
	--> A / B ���ڿ��� ���� �� �ִ� ��� ������ �� ���س��´�.
	--> client �� ���ϴ� ���� A / B ���ڿ��� �����ؼ� ����� ��� ���� ��� ����.
*/

#include<iostream>

using namespace std;

int client, nA, nB;
int pizzaA[1000], pizzaB[1000]; // pizza ������
int sizeA[1000001] = {}, sizeB[1000001] = {}; // pizza �������� ���� �� �ִ� ũ�� count
int ans = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> client >> nA >> nB;
	for (int i = 0; i < nA; i++)
		cin >> pizzaA[i];
	for (int i = 0; i < nB; i++)
		cin >> pizzaB[i];

	// pizzaA, pizzaB�� ������� ���� �� �ִ� ��� ũ�⸦ �� ������.
	// --> ���� ũ�� 0�� �ƹ��͵� �� �����ϸ� �ǹǷ� 1�� ����!
	// --> ��� ������ �� ������ ��츸 ���� ���� �������ش�.
	sizeA[0] = 1, sizeB[0] = 1; 
	int sum = 0;
	for (int i = 0; i < nA; i++)
		sum += pizzaA[i];
	sizeA[sum]++;
	sum = 0;
	for (int i = 0; i < nB; i++)
		sum += pizzaB[i];
	sizeB[sum]++;
	// i�� ° �������� �����ؼ� ��� ������ �����ϱ� ������ ���� �յ��� �� count ���ش�.
	for (int i = 0; i < nA; i++) {
		int sum = 0;
		for (int j = 0; j < nA - 1; j++) {
			sum += pizzaA[(i + j) % nA];
			sizeA[sum]++;
		}
	}
	for (int i = 0; i < nB; i++) {
		int sum = 0;
		for (int j = 0; j < nB - 1; j++) {
			sum += pizzaB[(i + j) % nB];
			sizeB[sum]++;
		}
	}
	// client �� ���ϴ� ������ �� �� ���� �� �ִ��� count ���ش�.
	for (int i = 0; i <= client; i++)
		ans += (sizeA[i] * sizeB[client - i]);

	cout << ans << '\n';
}