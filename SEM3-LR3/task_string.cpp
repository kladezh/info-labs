#include "task_string.h"

void task_string() {
	std::string substr;
	std::vector<std::string> words;

	// write substr
	std::cout << "введите подстроку: ";
	std::cin >> substr;

	// write words
	int size;
	std::cout << "\nвведите кол-во слов: ";
	std::cin >> size;
	words.resize(size);

	std::cout << "\nвведите слова:\n";
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
		int pos = 2 - substr.size(); // начиная с 3 символа
		int count = 0;
		while ((pos = word.find(substr, pos + substr.size())) != std::string::npos) {
			count++;
		}

		if (count > 1) { // больше 1 раза
			sentense.append(word.substr(0, 2) + ' '); // первые 2 символа
		}
	}

	// print sentense
	std::cout << "\nИтоговое предолжение:\n" << sentense << "\n";
}