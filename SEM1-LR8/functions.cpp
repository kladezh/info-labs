#include "functions.h"

// функция возвращает длину строки
int getLenght(const char* string) {
	int i = 0;

	while (string[i] != '\0') i++;

	return i;
}

// функция сравнивает посимвольно две строки и возвращает истину или ложь 
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

// функция символы в строке seq переставляет по соответствию со строкой str (если таковы символы есть)
// и после цикла перестановки сравнивает две строки 
bool isEqualComb(char* seq, const char* str) {
	int i, j;
	char tmp;
	bool f;

	if (getLenght(seq) != getLenght(str)) {
		f = false;
	}
	else {
		for (i = 0; i < getLenght(str); i++) {
			for (j = i; j < getLenght(seq); j++) {
				if (seq[j] == str[i]) {
					if (j != i) {
						tmp = seq[j];
						seq[j] = seq[i];
						seq[i] = tmp;
					}
					break;
				}
			}
		}
		f = isEqualStrs(seq, str);
	}

	return f;
}

// функция ищет в строке str подстроку needStr и возращает индекс первого вхождения (если совпадений нет, то функция вернет -1)
int isNeedStr(const char* str, const char* needStr) {
	int firstNum = -1;
	bool f;

	int lenStr = getLenght(str);
	int lenNeedStr = getLenght(needStr);

	char* subStr = (char*)malloc(sizeof(char) * (lenNeedStr + 1));
	subStr[lenNeedStr] = '\0';


	for (int i = 0; i < lenStr - lenNeedStr + 1; i++) {

		for (int j = 0; j < lenNeedStr; j++) {
			subStr[j] = str[i + j];
		}

		f = isEqualComb(subStr, needStr);
		if (f == true) {
			firstNum = i;
			break;
		}
	}

	free(subStr);
	return firstNum;
}

void endPoint(char* str) {
	int k;
	bool f = false;

	for (k = 0; k < getLenght(str); k++) {
		if (f == true) {
			str[k] = '\0';
		}
		else if (str[k] == '.') {
			f = true;
			str[k] = '\0';
		}
	}
}
