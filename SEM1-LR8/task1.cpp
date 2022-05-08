#include "task1.h"

void task1() {
	char* a = (char*)malloc(sizeof(char) * MAX_SIZE);
	char* b = (char*)malloc(sizeof(char) * MAX_SIZE);

	printf("Enter your sequence of symbols:\n"); // считываем строку 
	gets(a);
	printf("Enter your word :\n"); // считываем необходимую подстроку (в задании "char")
	gets(b);
	endPoint(a);

	int i; // получаем индекс первого вхождения и проверяем было ли оно 
	i = isNeedStr(a, b);

	if (i != -1) {
		printf("The string was found!\n");
		printf("Need string begins with %d number.\n", i);
	}
	else printf("The string was not found...");
}