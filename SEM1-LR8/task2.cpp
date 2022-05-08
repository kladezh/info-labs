#include "task2.h"

// функци€ принимает строку и подстроку, удал€ет все найденные подстроки в строке и возвращает изменненую строку
char* removeStr(char* str, const char* needStr) {
	int num;
	int lenStr, lenNeedStr;
	int i, j, tmp;

	// цикл удал€ет подстроку, но перед этим он еЄ естественно находит, вызыва€ функцию сравнени€ строк
	while (isNeedStr(str, needStr) != -1) {
		num = isNeedStr(str, needStr);

		lenNeedStr = getLenght(needStr);
		lenStr = getLenght(str);

		// у нас есть номер первого символа подстроки и есть длины строк
		// опериру€ этим добираемс€ до нужной подстроки и с последнего символа подстроки выталкиваем символы в конец   
		for (i = num + lenNeedStr - 1; i >= num; i--) {
			for (j = i; j < lenStr - 1; j++) {
				tmp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = str[j];
			}
		}
		// теперь подстрока в конце, и мы присваем ей нули-символы
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

	// вызываем функцию удалени€ подстроки из строки, но перед этим сохраним длину строки до изменнений 
	int lenOldStr = getLenght(a);
	a = removeStr(a, b);
	int lenNewStr = getLenght(a);

	// проверим длину строки до и после изменений, чтобы пон€ть - нашлась ли подстрока в строке
	if (lenOldStr != lenNewStr) {
		printf("Result :\n");
		puts(a);
	}
	else printf("There is no your combination in the string...\n");

	free(a);
	free(b);
}