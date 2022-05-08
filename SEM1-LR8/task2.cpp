#include "task2.h"

// ������� ��������� ������ � ���������, ������� ��� ��������� ��������� � ������ � ���������� ���������� ������
char* removeStr(char* str, const char* needStr) {
	int num;
	int lenStr, lenNeedStr;
	int i, j, tmp;

	// ���� ������� ���������, �� ����� ���� �� � ����������� �������, ������� ������� ��������� �����
	while (isNeedStr(str, needStr) != -1) {
		num = isNeedStr(str, needStr);

		lenNeedStr = getLenght(needStr);
		lenStr = getLenght(str);

		// � ��� ���� ����� ������� ������� ��������� � ���� ����� �����
		// �������� ���� ���������� �� ������ ��������� � � ���������� ������� ��������� ����������� ������� � �����   
		for (i = num + lenNeedStr - 1; i >= num; i--) {
			for (j = i; j < lenStr - 1; j++) {
				tmp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = str[j];
			}
		}
		// ������ ��������� � �����, � �� �������� �� ����-�������
		for (i = lenStr - lenNeedStr; i < lenStr; i++) {
			str[i] = '\0';
		}
	}

	return str;
}

void task2() {
	char* a = (char*)malloc(sizeof(char) * MAX_SIZE);
	char* b = (char*)malloc(sizeof(char) * MAX_SIZE);

	printf("Enter the string:\n");
	gets(a);
	printf("Enter the combination of symbols that need to remove:\n");
	gets(b);
	endPoint(a);

	// �������� ������� �������� ��������� �� ������, �� ����� ���� �������� ����� ������ �� ���������� 
	int lenOldStr = getLenght(a);
	a = removeStr(a, b);
	int lenNewStr = getLenght(a);

	// �������� ����� ������ �� � ����� ���������, ����� ������ - ������� �� ��������� � ������
	if (lenOldStr != lenNewStr) {
		printf("Result :\n");
		puts(a);
	}
	else printf("There is no your combination in the string...\n");

	free(a);
	free(b);
}