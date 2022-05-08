#include "functions.h"

// возвращает длинну строки
int getLenght(const char* string) {
	int i = 0;

	while (string[i] != '\0') i++;

	return i;
}
// копирует строку stringGive в строку stringTake, приэтом stringTake не изменяется в размере, если она меньше stringGive
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
// возвращает результат сравнения двух строк
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

// обнуляет в структуре массив bday и делает строки пустыми (не знаю как контролируется утечка данных, но я сделал так) 
void rubStruct(note* blocknote, const int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		// т.к. в функции addStruct, при передаче данных в новый массив стуркур, массивы символов на куче не изменяются
		// то нужно просто "обнулить" старые указатели
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

// выделяет на куче память под новый массив структур, увеличенный на 1, и передает в него старые значения
note* addStruct(note* oldStruct, int* size) {
	int k;
	(*size)++;

	if (*size == 1) {
		// если это первая структура, то просто выделяется память 
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
	// размер массива структур после добалнения равен кол-ву структур и он изменяется здесь (209 строка)
}
// выделяет на куче память под новый массив структур, уменьшенный на 1, и передает в него старые значения
// функция получает также номер структуры, которую нужно удалить
note* delStruct(note* oldStruct, int* size, int i) {
	int k;
	note* newStruct;

	if (i >= 1 && i <= *size) {

		if (*size == 1) {
			newStruct = NULL;
		}
		else {
			// выбранная структура перестаскивается в конец и не передается в новый массив
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
		(*size)--; // изменение размера массива структур

	}
	else exit(1);

	writeData(newStruct, *size);

	return newStruct;
}

// функция ввода данных в структуру
note* inputData(note* blocknote, int* size) {
	// выделение памяти для новой структуры
	blocknote = addStruct(blocknote, size);

	int i = (*size) - 1;
	char nameBuf[256]; // для ввода имени и фамилии
	char teleBuf[256]; // для ввода номера телефона

	printf("Enter the info about %dth person:\n", i + 1);

	blocknote[i].name = (char**)malloc(sizeof(char*) * 2); // указатель на массив массивов символов
	char* forPrintInputName[2] = { "First name : ","Last name : " }; // для вывода разных строк в цикле  
	for (int j = 0; j < 2; j++) {
		printf("%s", forPrintInputName[j]);
		// считывается строка в буфер, выделяется память у данных структуры такой же длины, и строка с буфера копируется в стркутуру
		gets(nameBuf);
		blocknote[i].name[j] = (char*)malloc(sizeof(char) * (getLenght(nameBuf) + 1));
		blocknote[i].name[j][getLenght(nameBuf)] = '\0';
		strCopy(blocknote[i].name[j], nameBuf);
	}

	// номер телефон аналогично имени
	printf("Telephone's number : ");
	gets(teleBuf);
	blocknote[i].tele = (char*)malloc(sizeof(char) * (getLenght(teleBuf) + 1));
	blocknote[i].tele[(getLenght(teleBuf))] = '\0';
	strCopy(blocknote[i].tele, teleBuf);

	// просто считывание чисел
	printf("Birth's day : ");
	for (int j = 0; j < 3; j++) {
		scanf_s("%d", &blocknote[i].bday[j]);
	}
	printf("\n");

	// запись данных в файл, путем добавления в конец файла
	writeData(blocknote, *size);

	return blocknote;
}
// отдельная функция замены имени/фамилии в изменении структуры
void changeName(note* blocknote, const int i, const int j) {
	char nameBuf[256];

	printf("Enter new name (previous value - %s) :\n", blocknote[i].name[j]);
	gets(nameBuf);

	free(blocknote[i].name[j]);
	blocknote[i].name[j] = (char*)malloc(sizeof(char) * (getLenght(nameBuf) + 1));
	blocknote[i].name[j][getLenght(nameBuf)] = '\0';
	strCopy(blocknote[i].name[j], nameBuf);
}
// замена данных структуры
void changeData(note* blocknote, const int size) {
	int i; // номер человека
	int choice; // выбор данных

	printf("Enter the number of the person who you want to change : ");
	scanf_s("%d", &i);
	if (i < 1 || i > size) { return; }

	printf("Choice the data : 1 - first name, 2 - last name, 3 - tele, 4 - birth's day : ");
	scanf_s("%d", &choice);
	getchar(); // съесть enter

	i--; // уменьшаем номер,т.к. в дальнейшем он нужен как порядковый индекс, а не кол-во 
	switch (choice) {
	case 1: { // изменение имени
		choice--;
		changeName(blocknote, i, choice);

		break;
	}
	case 2: { // изменение фамилии
		choice--;
		changeName(blocknote, i, choice);

		break;
	}
	case 3: { // изменение номера телефона (также как в вводе)
		char teleBuf[256];

		printf("Enter new number (previous value - %s) :\n", blocknote[i].tele);
		gets(teleBuf);

		free(blocknote[i].tele);
		blocknote[i].tele = (char*)malloc(sizeof(char) * (getLenght(teleBuf) + 1));
		blocknote[i].tele[getLenght(teleBuf)] = '\0';
		strCopy(blocknote[i].tele, teleBuf);

		break;
	}
	case 4: { // изменение даты др
		int k;

		printf("Enter new birth's day (previous value - ");
		for (k = 0; k < 3; k++) { printf("%d.", blocknote[i].bday[k]); }
		printf(") :\n"); // вывод старого значения внутри скобок 

		for (k = 0; k < 3; k++) {
			scanf_s("%d", &blocknote[i].bday[k]);
		}

		break;
	}
	default: break;
	}

	writeData(blocknote, size);
}

// функция вывода данных 
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
// функция вывода указанной пользователем структуры 
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

// чтение файла
note* readData(note* blocknote, int* size) {
	FILE* f; // указатель на поток чтения файла
	errno_t err; // это требование компилятора Visual Studio. Вообще, открытие, закрытие и проверки я взял с сайта Майкрософт об их компиляторе этом 

	err = fopen_s(&f, FILENAME, "rb"); // открытие для чтения в двоичном режиме
	if (err != 0) { // проверка на ошибки
		printf("file was not opened (for read)...\n");
		exit(1);
	}
	if (f) { // если указатель не NULL, то можно работать

		// проверка на пустоту файла:
		fseek(f, 0, SEEK_END); // сдвиг указателя в конец файла
		long int endf = ftell(f); // кол-бо байт по положению указателя
		if (endf > 0) { // файл непустой
			rewind(f); // возвращение указателя в начало файла

			//считывание данных: (данные структур (имя, телефон и т.д.) записаны в строку и разделены между собой и другими структурами символом ';') 
			//ещё в файл перед данными записывается номер стурктуры в массиве, для того чтобы выделить память
			char fchn;

			while ((fchn = fgetc(f)) != EOF) { // считывается порядковый номер 

				*size = fchn;
				blocknote = addStruct(blocknote, size); // выделение памяти для структуры, там же увеличится размер на 1

				// принцип считывания строк тот же, что и в inputData(), то есть через буффер и копирование
				int i, j, k;
				char strBuf[256];
				char fch;

				i = (*size) - 1; // порядковый номер

				blocknote[i].name = (char**)malloc(sizeof(char*) * 2);
				for (j = 0; j < 2; j++) {
					// считывание символов и запись в буффер до тех пор, пока не упрется в разделитель ';'
					k = 0;
					while ((fch = fgetc(f)) != ';' && fch != EOF) {
						strBuf[k] = fch;
						k++;
					}
					strBuf[k] = '\0';
					// копирование строки из буффера в структуру
					blocknote[i].name[j] = (char*)malloc(sizeof(char) * (getLenght(strBuf) + 1));
					blocknote[i].name[j][getLenght(strBuf)] = '\0';
					strCopy(blocknote[i].name[j], strBuf);

					for (k = 0; k < getLenght(strBuf); k++) {// обнуления буффера для следующего захода на фамилию
						strBuf[k] = '\0';
					}
				}

				// аналогично для номера телефона
				k = 0;
				while ((fch = fgetc(f)) != ';' && fch != EOF) {
					strBuf[k] = fch;
					k++;
				}
				strBuf[k] = '\0';
				blocknote[i].tele = (char*)malloc(sizeof(char) * (getLenght(strBuf) + 1));
				blocknote[i].tele[getLenght(strBuf)] = '\0';
				strCopy(blocknote[i].tele, strBuf);

				fread(blocknote[i].bday, sizeof(int), 3, f); // чтение чисел массива дня рождения

				fseek(f, sizeof(char), SEEK_CUR); // сдвиг указатель в файле на 1 байт, чтобы перескочить разделитель ';' между структурами
			}
		}

		// закрытие файла
		err = fclose(f);
		if (err != 0) {
			printf("file was not closed (after read)...");
		}
	}

	return blocknote;
}

// запись в файл
void writeData(note* blocknote, int size) {
	FILE* f;
	errno_t err;

	err = fopen_s(&f, FILENAME, "ab"); // открыть для бинарного добавления в конец файла
	if (err != 0) {
		printf("file was not opened (for write)...%d\n", err);
	}
	if (f) {

		int i = size - 1;

		fputc(i, f);// порядковый номер структуры в массиве
		// запись 4 массивов со структуры (name - 2 массива) и в конце каждого - разделитель
		for (int j = 0; j < 2; j++) {
			fwrite(blocknote[i].name[j], sizeof(char), getLenght(blocknote[i].name[j]), f);
			fputc(';', f);
		}
		fwrite(blocknote[i].tele, sizeof(char), getLenght(blocknote[i].tele), f);
		fputc(';', f);
		fwrite(blocknote[i].bday, sizeof(int), 3, f);
		fputc(';', f);

		err = fclose(f); // закрытие файла
		if (err != 0) {
			printf("file was not closed (after write)...\n");
		}
	}

}
