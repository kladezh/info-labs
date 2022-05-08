#include <iostream>
#include <string>
#include <vector>

// ����� �����
class SymbString {
protected:
	std::string _data;

public:
	SymbString()
	{
	}
	SymbString(const std::string& data) : _data(data)
	{
	}

	virtual std::string data() const { return _data; }

	friend std::ostream& operator<<(std::ostream& out, const SymbString& str);
};

std::ostream& operator<<(std::ostream& out, const SymbString& str) {
	out << str.data();
	return out;
}

// ����� �����, ��������� �� ���������� ����
class DecString : public SymbString {
public:
	// ����������� �� ���������
	DecString()
	{
	}
	// ����������� ��������� string � ��������� �� �����
	DecString(const std::string& data)
	{
		for (int i = 0; i < data.size(); i++) {
			if (!isdigit(data.at(i))) {
				if (i == 0 && data.at(i) != '-') {
					std::cout << "\n DecString can't contain not-numeral characters...\n";
					exit(1);
				}
			}
		}

		_data = data;
	}
	// ����������� ��������� int � ������������ � string
	DecString(int data) : SymbString(std::to_string(data))
	{
	}

	// ����� ���������� ������ � ���� ����� - � ��������
	int numData() const { return std::stoi(_data); }
};

//�����, ���������� ������ ���� ���������� ����� (SymbString*)
class Factory {
private:
	std::vector<SymbString*> _vec;

public:
	Factory()
	{
	}
	~Factory()
	{
		for (auto obj : _vec) {
			if (obj) delete obj;
		}
	}

	std::vector<SymbString*> list() { return _vec; }
	int size() const { return _vec.size(); }

	SymbString* getObj(int index) { return _vec.at(index); }

	// ������� (�������� � ������) ���������� ������
	void createSymbString(const std::string& str) {
		_vec.push_back(new SymbString(str));
	}
	// ������� (�������� � ������) ������ �� ���� (������� string ��� int)
	void createDecString(const std::string& str) {
		_vec.push_back(new DecString(str));
	}
	void createDecString(int str) {
		_vec.push_back(new DecString(str));
	}

	// ������� ��������� ������ � �������
	void destroyObj() {
		delete _vec[_vec.size() - 1];
		_vec.pop_back();
	}
	// ������� ������ �� �������
	void destroyObj(int index) {
		delete _vec[index];
		_vec.erase(_vec.begin() + index);
	}

	// ������ ��������
	void print() const {
		for (int i = 0; i < _vec.size(); i++) {
			std::cout << "object[" << i << "] : " << _vec.at(i)->data() << "\n";
		}
		std::cout << "\n";
	}
};

int main() {
	// ������
	Factory f;

	// �������� �����
	f.createSymbString("man");
	f.createDecString(100); // �������������� � "100"
	f.createDecString("709");

	// ������ ��������
	f.print();

	// ������� ��������� ������
	f.destroyObj(); // delete "709"

	// ������ ��������
	f.print();

	// �������� SymbString �� DecString � �������� ��� ����� numData()
	std::cout << "DecString(100) * 20 = " << dynamic_cast<DecString*>(f.getObj(1))->numData() * 20 << "\n";

	// �������� ��������
	std::cout << "result of sum : " << f.getObj(0)->data() + f.getObj(1)->data() << std::endl;

	return 0;
}
