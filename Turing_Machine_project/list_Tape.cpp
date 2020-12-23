//��� �� ���������� ������� �� ������� ���� std::list
#include<string>
#include<fstream>
#include<vector>
#include<list>
#include <iostream>

/*
����������� ������� ���� ������� ������.
�� �� ��������� ���������,������ ���� ���������� �� ������� ����.��-������ � ��������� ��������������
�� ������.
*/
class Tape
{
private:
	std::list<char> tape;
public:
	Tape();
	~Tape();
	//��������� �� ���������� �� ������� ����
	void input(std::string);
	//��������� �� ���������� � ������� ����
	void output(std::string);
	//������� ����������� �� ������� �� ���������
	void print();
	//
	std::list<char>& getTape() {
		return tape;
	}

};




Tape::Tape() {

}


//������� ������� �� ������� �� ����
void Tape::input(std::string filename)
{
	std::ifstream is;
	char symbol;

	is.open(filename);
	//��������� ���� ������ � �������
	if (is.is_open()) {

		//������� ������� ������ �� ������ ���� �� �����
		while (is) {
			is >> symbol;
			tape.push_back(symbol);
		}
		is.close();
	}
	else std::cerr << "Cannot open file!";
}


//������� ��� ���� ��������� �� �������
void Tape::output(std::string filename)
{

	std::ofstream os;
	os.open(filename);
	// ��������� �� ���� ������ � �������.��� �� �, �� ������� ��������� �� ������
	if (os.is_open()) {
		// �������� �� ��������� �� ������� ��� �����, ������ �� �� ������ ������� ����
		for (char c : tape) {
			os << c;
		}
		os.close();
	}
	else std::cerr << "Cannot open the file successfully!";
}


void Tape::print()
{
	for (char c : tape) {
		std::cout << c << " ";
	}
}


Tape::~Tape()
{

}




