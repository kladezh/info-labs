#include "functions.h"

// ���������� ������ ������
int getLenght(const char* string) {
	int i = 0;

	while (string[i] != '\0') i++;

	return i;
}
// �������� ������ stringGive � ������ stringTake, ������� stringTake �� ���������� � �������, ���� ��� ������ stringGive
void strCopy(char* stringTake, const char* stringGive) {
	int i;
	int lenStrTake = getLenght(stringTake);
	int lenStrGive = getLenght(stringGive);
	int len = lenStrTake;
	if (lenStrTake > lenStrGive) {
		len = lenStrGive;
	}

	for (i = 0; i < len; i++) {
		stringTake[i] = stringGive[i];
	}
	for (i = lenStrGive; i < lenStrTake; i++) {
		stringTake[i] = '\0';
	}
}
// ���������� ��������� ��������� ���� �����
bool isEqualStrs(const char* a, const char* b) {
	bool f = false;
	int k = 0;
	int len = getLenght(a);

	for (int i = 0; i < len; i++) {
		if (a[i] == b[i]) k++;
	}
	if (k == len) f = true;

	return f;
}

// �������� � ��������� ������ bday � ������ ������ ������� (�� ���� ��� �������������� ������ ������, �� � ������ ���) 
void rubStruct(note* blocknote, const int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		// �.�. � ������� addStruct, ��� �������� ������ � ����� ������ �������, ������� �������� �� ���� �� ����������
		// �� ����� ������ "��������" ������ ���������
		blocknote[i].name = NULL;
		blocknote[i].tele = NULL;

		for (j = 0; j < 3; j++) {
			blocknote[i].bday[j] = 0;
		}

	}
}
void sortData(note* blocknote, const int size) {
	int i, j;
	char strCur[3 + 1], strNext[3 + 1];
	strCur[3] = '\0'; strNext[3] = '\0';
	int valStrCur, valStrNext;
	note tempStruct;

	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			strCopy(strCur, blocknote[j].tele);
			strCopy(strNext, blocknote[j + 1].tele);
			valStrCur = atoi(strCur);
			valStrNext = atoi(strNext);

			if (valStrCur > valStrNext) {
				tempStruct = blocknote[j];
				blocknote[j] = blocknote[j + 1];
				blocknote[j + 1] = tempStruct;
			}
		}
	}
}

// �������� �� ���� ������ ��� ����� ������ ��������, ����������� �� 1, � �������� � ���� ������ ��������
note* addStruct(note* oldStruct, int* size) {
	int k;
	(*size)++;

	if (*size == 1) {
		// ���� ��� ������ ���������, �� ������ ���������� ������ 
		oldStruct = (note*)malloc(sizeof(note));
	}
	else {
		note* newStruct = (note*)malloc((*size) * sizeof(note));
		for (k = 0; k < (*size) - 1; k++) {
			newStruct[k] = oldStruct[k];
		}
		rubStruct(oldStruct, *(size)-1);
		free(oldStruct);

		oldStruct = newStruct;
	}

	return oldStruct;
	// ������ ������� �������� ����� ���������� ����� ���-�� �������� � �� ���������� ����� (209 ������)
}
// �������� �� ���� ������ ��� ����� ������ ��������, ����������� �� 1, � �������� � ���� ������ ��������
// ������� �������� ����� ����� ���������, ������� ����� �������
note* delStruct(note* oldStruct, int* size, int i) {
	int k;
	note* newStruct;

	if (i >= 1 && i <= *size) {

		if (*size == 1) {
			newStruct = NULL;
		}
		else {
			// ��������� ��������� ���������������� � ����� � �� ���������� � ����� ������
			newStruct = (note*)malloc(((*size) - 1) * sizeof(note));
			for (k = i - 1; k < (*size) - 1; k++) {
				newStruct[0] = oldStruct[k];
				oldStruct[k] = oldStruct[k + 1];
				oldStruct[k + 1] = newStruct[0];
			}
			for (k = 0; k < (*size) - 1; k++) {
				newStruct[k] = oldStruct[k];
			}
		}

		rubStruct(oldStruct, *size);
		free(oldStruct);
		(*size)--; // ��������� ������� ������� ��������

	}
	else exit(1);

	writeData(newStruct, *size);

	return newStruct;
}

// ������� ����� ������ � ���������
note* inputData(note* blocknote, int* size) {
	// ��������� ������ ��� ����� ���������
	blocknote = addStruct(blocknote, size);

	int i = (*size) - 1;
	char nameBuf[256]; // ��� ����� ����� � �������
	char teleBuf[256]; // ��� ����� ������ ��������

	printf("Enter the info about %dth person:\n", i + 1);

	blocknote[i].name = (char**)malloc(sizeof(char*) * 2); // ��������� �� ������ �������� ��������
	char* forPrintInputName[2] = { "First name : ","Last name : " }; // ��� ������ ������ ����� � �����  
	for (int j = 0; j < 2; j++) {
		printf("%s", forPrintInputName[j]);
		// ����������� ������ � �����, ���������� ������ � ������ ��������� ����� �� �����, � ������ � ������ ���������� � ���������
		gets(nameBuf);
		blocknote[i].name[j] = (char*)malloc(sizeof(char) * (getLenght(nameBuf) + 1));
		blocknote[i].name[j][getLenght(nameBuf)] = '\0';
		strCopy(blocknote[i].name[j], nameBuf);
	}

	// ����� ������� ���������� �����
	printf("Telephone's number : ");
	gets(teleBuf);
	blocknote[i].tele = (char*)malloc(sizeof(char) * (getLenght(teleBuf) + 1));
	blocknote[i].tele[(getLenght(teleBuf))] = '\0';
	strCopy(blocknote[i].tele, teleBuf);

	// ������ ���������� �����
	printf("Birth's day : ");
	for (int j = 0; j < 3; j++) {
		scanf_s("%d", &blocknote[i].bday[j]);
	}
	printf("\n");

	// ������ ������ � ����, ����� ���������� � ����� �����
	writeData(blocknote, *size);

	return blocknote;
}
// ��������� ������� ������ �����/������� � ��������� ���������
void changeName(note* blocknote, const int i, const int j) {
	char nameBuf[256];

	printf("Enter new name (previous value - %s) :\n", blocknote[i].name[j]);
	gets(nameBuf);

	free(blocknote[i].name[j]);
	blocknote[i].name[j] = (char*)malloc(sizeof(char) * (getLenght(nameBuf) + 1));
	blocknote[i].name[j][getLenght(nameBuf)] = '\0';
	strCopy(blocknote[i].name[j], nameBuf);
}
// ������ ������ ���������
void changeData(note* blocknote, const int size) {
	int i; // ����� ��������
	int choice; // ����� ������

	printf("Enter the number of the person who you want to change : ");
	scanf_s("%d", &i);
	if (i < 1 || i > size) { return; }

	printf("Choice the data : 1 - first name, 2 - last name, 3 - tele, 4 - birth's day : ");
	scanf_s("%d", &choice);
	getchar(); // ������ enter

	i--; // ��������� �����,�.�. � ���������� �� ����� ��� ���������� ������, � �� ���-�� 
	switch (choice) {
	case 1: { // ��������� �����
		choice--;
		changeName(blocknote, i, choice);

		break;
	}
	case 2: { // ��������� �������
		choice--;
		changeName(blocknote, i, choice);

		break;
	}
	case 3: { // ��������� ������ �������� (����� ��� � �����)
		char teleBuf[256];

		printf("Enter new number (previous value - %s) :\n", blocknote[i].tele);
		gets(teleBuf);

		free(blocknote[i].tele);
		blocknote[i].tele = (char*)malloc(sizeof(char) * (getLenght(teleBuf) + 1));
		blocknote[i].tele[getLenght(teleBuf)] = '\0';
		strCopy(blocknote[i].tele, teleBuf);

		break;
	}
	case 4: { // ��������� ���� ��
		int k;

		printf("Enter new birth's day (previous value - ");
		for (k = 0; k < 3; k++) { printf("%d.", blocknote[i].bday[k]); }
		printf(") :\n"); // ����� ������� �������� ������ ������ 

		for (k = 0; k < 3; k++) {
			scanf_s("%d", &blocknote[i].bday[k]);
		}

		break;
	}
	default: break;
	}

	writeData(blocknote, size);
}

// ������� ������ ������ 
void printTable(note* blocknote, const int size) {
	int i;

	printf("\n");

	printf("N  ");
	printf("FirstName\tLastName\tTelephone's number\tBirth'sDay\n");
	printf("==================================================================\n");
	if (size == 0) {
		printf(" -     - - -        - - -         - - -    \n");
	}
	else {
		if (size > 1) sortData(blocknote, size);

		for (i = 0; i < size; i++) {
			printf("%d  ", i + 1);
			printf("%-12s\t%-12s\t%-20s\t%d.%d.%d",
				blocknote[i].name[0], blocknote[i].name[1],
				blocknote[i].tele,
				blocknote[i].bday[0], blocknote[i].bday[1], blocknote[i].bday[2]
			);
			printf("\n");
		}
	}
	printf("\n");
}
// ������� ������ ��������� ������������� ��������� 
void printTableOne(note* blocknote, const int i) {
	printf("\n");

	printf("N  ");
	printf("FirstName\tLastName\tTelephone's number\tBirth'sDay\n");
	printf("=========================================================\n");

	printf("%d  ", i + 1);
	printf("%-8s\t%-8s\t%-20s\t%d.%d.%d",
		blocknote[i].name[0], blocknote[i].name[1],
		blocknote[i].tele,
		blocknote[i].bday[0], blocknote[i].bday[1], blocknote[i].bday[2]
	);
	printf("\n");

	printf("\n");
}

// ������ �����
note* readData(note* blocknote, int* size) {
	FILE* f; // ��������� �� ����� ������ �����
	errno_t err; // ��� ���������� ����������� Visual Studio. ������, ��������, �������� � �������� � ���� � ����� ���������� �� �� ����������� ���� 

	err = fopen_s(&f, FILENAME, "rb"); // �������� ��� ������ � �������� ������
	if (err != 0) { // �������� �� ������
		printf("file was not opened (for read)...\n");
		exit(1);
	}
	if (f) { // ���� ��������� �� NULL, �� ����� ��������

		// �������� �� ������� �����:
		fseek(f, 0, SEEK_END); // ����� ��������� � ����� �����
		long int endf = ftell(f); // ���-�� ���� �� ��������� ���������
		if (endf > 0) { // ���� ��������
			rewind(f); // ����������� ��������� � ������ �����

			//���������� ������: (������ �������� (���, ������� � �.�.) �������� � ������ � ��������� ����� ����� � ������� ����������� �������� ';') 
			//��� � ���� ����� ������� ������������ ����� ��������� � �������, ��� ���� ����� �������� ������
			char fchn;

			while ((fchn = fgetc(f)) != EOF) { // ����������� ���������� ����� 

				*size = fchn;
				blocknote = addStruct(blocknote, size); // ��������� ������ ��� ���������, ��� �� ���������� ������ �� 1

				// ������� ���������� ����� ��� ��, ��� � � inputData(), �� ���� ����� ������ � �����������
				int i, j, k;
				char strBuf[256];
				char fch;

				i = (*size) - 1; // ���������� �����

				blocknote[i].name = (char**)malloc(sizeof(char*) * 2);
				for (j = 0; j < 2; j++) {
					// ���������� �������� � ������ � ������ �� ��� ���, ���� �� ������� � ����������� ';'
					k = 0;
					while ((fch = fgetc(f)) != ';' && fch != EOF) {
						strBuf[k] = fch;
						k++;
					}
					strBuf[k] = '\0';
					// ����������� ������ �� ������� � ���������
					blocknote[i].name[j] = (char*)malloc(sizeof(char) * (getLenght(strBuf) + 1));
					blocknote[i].name[j][getLenght(strBuf)] = '\0';
					strCopy(blocknote[i].name[j], strBuf);

					for (k = 0; k < getLenght(strBuf); k++) {// ��������� ������� ��� ���������� ������ �� �������
						strBuf[k] = '\0';
					}
				}

				// ���������� ��� ������ ��������
				k = 0;
				while ((fch = fgetc(f)) != ';' && fch != EOF) {
					strBuf[k] = fch;
					k++;
				}
				strBuf[k] = '\0';
				blocknote[i].tele = (char*)malloc(sizeof(char) * (getLenght(strBuf) + 1));
				blocknote[i].tele[getLenght(strBuf)] = '\0';
				strCopy(blocknote[i].tele, strBuf);

				fread(blocknote[i].bday, sizeof(int), 3, f); // ������ ����� ������� ��� ��������

				fseek(f, sizeof(char), SEEK_CUR); // ����� ��������� � ����� �� 1 ����, ����� ����������� ����������� ';' ����� �����������
			}
		}

		// �������� �����
		err = fclose(f);
		if (err != 0) {
			printf("file was not closed (after read)...");
		}
	}

	return blocknote;
}

// ������ � ����
void writeData(note* blocknote, int size) {
	FILE* f;
	errno_t err;

	err = fopen_s(&f, FILENAME, "ab"); // ������� ��� ��������� ���������� � ����� �����
	if (err != 0) {
		printf("file was not opened (for write)...%d\n", err);
	}
	if (f) {

		int i = size - 1;

		fputc(i, f);// ���������� ����� ��������� � �������
		// ������ 4 �������� �� ��������� (name - 2 �������) � � ����� ������� - �����������
		for (int j = 0; j < 2; j++) {
			fwrite(blocknote[i].name[j], sizeof(char), getLenght(blocknote[i].name[j]), f);
			fputc(';', f);
		}
		fwrite(blocknote[i].tele, sizeof(char), getLenght(blocknote[i].tele), f);
		fputc(';', f);
		fwrite(blocknote[i].bday, sizeof(int), 3, f);
		fputc(';', f);

		err = fclose(f); // �������� �����
		if (err != 0) {
			printf("file was not closed (after write)...\n");
		}
	}

}
