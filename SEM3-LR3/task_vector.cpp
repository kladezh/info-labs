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
	std::cout << "������:"; printV(numbers);

	// ����� ������������� �������
	int positive_min = 0;
	for (int num : numbers) {
		if (num > 0 && (num < positive_min || positive_min == 0)) {
			positive_min = num;
		}
	}
	std::cout << "������������� �������: " << positive_min << "\n";

	// �������� poitive_min � ������� �������������� �����
	for (int& num : numbers) {
		if (num < 0) {
			num += positive_min;
		}
	}
	std::cout << "�������� ������������� ��� � ������� �������������� �����:"; printV(numbers);

	// ������� ��� �����, ������� t
	int t = 2;
	for (auto it = numbers.begin(); it != numbers.end();) {
		if ((*it) % t == 0) {
			it = numbers.erase(it);
		}
		else {
			++it;
		}
	}
	std::cout << "������� ��� �����, ������� t=" << t << ":"; printV(numbers);

	// ������������� �������� ����� ��������� �� ��������
	int i1 = 2, i2 = 5;
	std::sort(numbers.begin() + i1, numbers.begin() + i2, [](int a, int b) {
		return a > b;
		});
	std::cout << "���������� �� �������� ����� i1=" << i1 << " � i2=" << i2 << ":"; printV(numbers);

	// ����� �������
	int min = numbers.at(0);
	for (int number : numbers) {
		if (number < min) {
			min = number;
		}
	}
	std::cout << "�������: " << min << "\n";

	// ������� ��� �����, ��� ���� ������� �� ����� ��������
	for (auto it = numbers.begin(); it != numbers.end();) {
		if (sign(*it) != sign(min)) {
			it = numbers.erase(it);
		}
		else {
			++it;
		}
	}
	std::cout << "������� ��� �����, ��� ���� ������� �� ����� ��������:"; printV(numbers);
}