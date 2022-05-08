#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct note {
	char** name;
	char* tele;
	int bday[3];
} note;

extern const char* FILENAME = "DataOfLaba9.dat";

int getLenght(const char* string);
void strCopy(char* stringTake, const char* stringGive);
bool isEqualStrs(const char* a, const char* b);

void rubStruct(note* blocknote, const int size);
void sortData(note* blocknote, const int size);

note* addStruct(note* oldStruct, int* size);
note* delStruct(note* oldStruct, int* size, int i);

note* inputData(note* blocknote, int* size);
void changeData(note* blocknote, const int size);
void changeName(note* blocknote, const int i, const int j);

void printTable(note* blocknote, const int size);
void printTableOne(note* blocknote, const int i);

note* readData(note* blocknote, int* size);
void writeData(note* blocknote, const int size);
