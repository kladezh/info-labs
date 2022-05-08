#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define MAX_SIZE 256

int getLenght(const char* string);

bool isEqualStrs(const char* a, const char* b);
bool isEqualComb(char* seq, const char* str);
int isNeedStr(const char* str, const char* needStr);

void endPoint(char* str);
