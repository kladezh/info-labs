#include "task_vector.h"

int sign(int value) {
	if (value > 0) return 1;
	if (value < 0) return -1;
	return 0;
}

void printV(const std::vector<int>& vector) {
	std::cout << "\n";
	for (int elem : vector) {
		std::cout << elem << ' ';
	}
	std::cout << "\n\n";
}

void task_string() {
	std::vector<int> numbers = { 1, -80, 66, -24, -2, 46, 89, -9, -14, 44 }; // size = 10
	std::cout << "Вектор:"; printV(numbers);

	// найти положительный минимум
	int positive_min = 0;
	for (int num : numbers) {
		if (num > 0 && (num < positive_min || positive_min == 0)) {
			positive_min = num;
		}
	}
	std::cout << "Положительный минимум: " << positive_min << "\n";

	// добавить poitive_min к каждому отрицательному числу
	for (int& num : numbers) {
		if (num < 0) {
			num += positive_min;
		}
	}
	std::cout << "Добавить положительный мин к каждому отрицательному числу:"; printV(numbers);

	// удалить все числа, кратные t
	int t = 2;
	for (auto it = numbers.begin(); it != numbers.end();) {
		if ((*it) % t == 0) {
			it = numbers.erase(it);
		}
		else {
			++it;
		}
	}
	std::cout << "Удалить все числа, кратные t=" << t << ":"; printV(numbers);

	// отсортировать элементы между индексами по убыванию
	int i1 = 2, i2 = 5;
	std::sort(numbers.begin() + i1, numbers.begin() + i2, [](int a, int b) {
		return a > b;
		});
	std::cout << "Сортировка по убыванию между i1=" << i1 << " и i2=" << i2 << ":"; printV(numbers);

	// найти минимум
	int min = numbers.at(0);
	for (int number : numbers) {
		if (number < min) {
			min = number;
		}
	}
	std::cout << "Минимум: " << min << "\n";

	// удалить все числа, чей знак отличен от знака минимума
	for (auto it = numbers.begin(); it != numbers.end();) {
		if (sign(*it) != sign(min)) {
			it = numbers.erase(it);
		}
		else {
			++it;
		}
	}
	std::cout << "Удалить все числа, чей знак отличен от знака минимума:"; printV(numbers);
}