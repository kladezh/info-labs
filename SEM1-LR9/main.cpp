#include "functions.h"

int main() {
	note* blocknote = NULL; // ��������� �� ������ ��������
	int n = 0; // ���-�� �������� � �������

	// ���������� ������ � ����� 
	blocknote = readData(blocknote, &n);

	// ���������� ������ ���������, ���� ���� ������
	if (n == 0) {
		blocknote = inputData(blocknote, &n);
	}

	//������ � ����������� �����������
	int choice = -1; // ��� switch 
	bool hidePrint = false; // ��� ��������� ������� ������, ��� �������� ����� �������� � ������ ���������������� ���������
	while (choice != 0) {

		if (hidePrint == false) {
			printTable(blocknote, n);
		}
		else hidePrint = false;
		printf("Please enter: 1 - to add person, 2 - to change info, 3 - to delete info, 4 - to show by last name, 0 - to exit\n");

		scanf_s("%d", &choice);
		getchar(); // ������ enter

		switch (choice) {
		case 1: { // ���������� ���������
			blocknote = inputData(blocknote, &n);

			break;
		}
		case 2: { // ��������� ������
			changeData(blocknote, n);

			break;
		}
		case 3: { // �������� ��������� 
			int i;

			printf("Enter the number of the person who you want to remove : ");
			scanf_s("%d", &i);
			if (i < 1 || i > n) break;

			blocknote = delStruct(blocknote, &n, i);

			printf("\n");

			break;
		}
		case 4: { // ����� ������ ��������� �� �������
			char lastName[128];
			bool f;

			printf("Enter last name you need : ");
			gets(lastName);

			for (int i = 0; i < n; i++) {
				f = isEqualStrs(lastName, blocknote[i].name[1]);
				if (f == true) {
					printTableOne(blocknote, i);
					break;
				}
			}
			if (f == false) printf("There is no such name...\n");

			hidePrint = true;
			break;
		}
		case 0: break; // ���������� ���������
		default: printf("You pressed the wrong key.Try again...\n"); hidePrint = true;
		}

	}
	printf("\n");

	return 0;
}
