#include "task1.h"

void task1() {
	char* a = (char*)malloc(sizeof(char) * MAX_SIZE);
	char* b = (char*)malloc(sizeof(char) * MAX_SIZE);

	printf("Enter your sequence of symbols:\n"); // ��������� ������ 
	gets(a);
	printf("Enter your word :\n"); // ��������� ����������� ��������� (� ������� "char")
	gets(b);
	endPoint(a);

	int i; // �������� ������ ������� ��������� � ��������� ���� �� ��� 
	i = isNeedStr(a, b);

	if (i != -1) {
		printf("The string was found!\n");
		printf("Need string begins with %d number.\n", i);
	}
	else printf("The string was not found...");
}