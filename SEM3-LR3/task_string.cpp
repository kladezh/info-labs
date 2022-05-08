#include "task_string.h"

void task_string() {
	std::string substr;
	std::vector<std::string> words;

	// write substr
	std::cout << "������� ���������: ";
	std::cin >> substr;

	// write words
	int size;
	std::cout << "\n������� ���-�� ����: ";
	std::cin >> size;
	words.resize(size);

	std::cout << "\n������� �����:\n";
	for (auto& word : words) {
		std::cin >> word;
	}

	// delete numbers and append '+'
	for (auto& word : words) {
		int origin_size = word.size();

		for (int i = 0; i < origin_size; i++) {
			char sym = word.at(i);

			if (isdigit(sym)) {
				word.erase(word.find(sym));
				word.push_back('+');
			}
		}
	}

	// create a sentense by some conditions
	std::string sentense;
	for (const auto& word : words) {
		int pos = 2 - substr.size(); // ������� � 3 �������
		int count = 0;
		while ((pos = word.find(substr, pos + substr.size())) != std::string::npos) {
			count++;
		}

		if (count > 1) { // ������ 1 ����
			sentense.append(word.substr(0, 2) + ' '); // ������ 2 �������
		}
	}

	// print sentense
	std::cout << "\n�������� �����������:\n" << sentense << "\n";
}