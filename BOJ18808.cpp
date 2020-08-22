/*
	�ùķ��̼� ����
	1) map�� ���� ��ܺ��� �����ؼ� ���� ��ƼĿ�� ���� �� �ִ��� üũ!
	2) ��� �κп� ���� ��ƼĿ�� ���� �� ���ٸ� ��ƼĿ�� rotate !
	3) rotate�� 4�� �����ؼ� ���� ��ƼĿ ������� ���ƿԴµ��� ���� �� ���ٸ� ��ƼĿ�� ������.
	4) ��ƼĿ�� ���� �� �ִٸ� ��ƼĿ�� '1' �κи� map���� �Ű��ش�.
*/
#include<iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int mapRows, mapCols, stickers;
	bool map[40][40] = {};
	cin >> mapRows >> mapCols >> stickers;
	for (int sticker = 0; sticker < stickers; sticker++) {
		// ��ƼĿ �Է�
		int stickerRows, stickerCols;
		bool stickerMap[10][10] = {};
		cin >> stickerRows >> stickerCols;
		for (int stickerR = 0; stickerR < stickerRows; stickerR++)
			for (int stickerC = 0; stickerC < stickerCols; stickerC++)
				cin >> stickerMap[stickerR][stickerC];

		// 4���⿡ ���ؼ� ��ƼĿ�� ��, ���ʺ��� �ٿ�����.
		for (int rotate = 0; rotate < 4; rotate++) {
			bool success = false;
			for (int j = 0; j <= mapRows - stickerRows; j++) {
				for (int k = 0; k <= mapCols - stickerCols; k++) {
					// map�� (j,k) ���� �����ؼ� ��ƼĿ�� �ٿ�����.
					bool fail = false;
					for (int stickerR = 0; stickerR < stickerRows; stickerR++) {
						for (int stickerC = 0; stickerC < stickerCols; stickerC++) {
							if (map[j + stickerR][k + stickerC] && stickerMap[stickerR][stickerC]) { // �̹� ��ƼĿ�� ���� ���� �ٿ����ϴ� ���
								fail = true;
								stickerR = stickerRows, stickerC = stickerCols;
							}
						}
					}
					if (!fail) {
						for (int stickerR = 0; stickerR < stickerRows; stickerR++)
							for (int stickerC = 0; stickerC < stickerCols; stickerC++)
								if (stickerMap[stickerR][stickerC]) map[j + stickerR][k + stickerC] = 1;
						j = mapRows - stickerRows + 1, k = mapCols - stickerCols + 1; //break;
						success = true;
					}
				}
			}
			if (success) break;

			// 90�� ȸ����Ű��
			bool copyStickerMap[10][10] = {};
			for(int stickerR = 0; stickerR < stickerCols; stickerR++)
				for(int stickerC = 0; stickerC < stickerRows; stickerC++)
					copyStickerMap[stickerR][stickerC] = stickerMap[stickerRows- 1 - stickerC][stickerR];
			int temp = stickerRows; // ȸ���ϴϱ� row, col SWAP
			stickerRows = stickerCols;
			stickerCols = temp;
			for (int stickerR = 0; stickerR < 10; stickerR++) // ȸ����Ų copyMap �������ֱ�
				for (int stickerC = 0; stickerC < 10; stickerC++)
					stickerMap[stickerR][stickerC] = copyStickerMap[stickerR][stickerC];

		}
	}
	int ans = 0;
	for (int mapR = 0; mapR < mapRows; mapR++)
		for (int mapC = 0; mapC < mapCols; mapC++)
			if (map[mapR][mapC]) ans++;

	cout << ans << '\n';
}