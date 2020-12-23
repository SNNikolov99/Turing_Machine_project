//Тук ще съхранявам вариант на лентата като std::list
#include<string>
#include<fstream>
#include<vector>
#include<list>
#include <iostream>

/*
Представяме лентата като свързан списък.
Ще се разширява динамично,докато чете информация от текстов файл.По-надолу е спомената функциалността
на обекта.
*/
class Tape
{
private:
	std::list<char> tape;
public:
	Tape();
	~Tape();
	//Въвеждане на информация от текстов файл
	void input(std::string);
	//извеждане на информация в текстов файл
	void output(std::string);
	//извежда инормацията на лентата на конзолата
	void print();
	//
	std::list<char>& getTape() {
		return tape;
	}

};




Tape::Tape() {

}


//въвежда символи на лентата от файл
void Tape::input(std::string filename)
{
	std::ifstream is;
	char symbol;

	is.open(filename);
	//проверява дали файлът е отворен
	if (is.is_open()) {

		//въвежда символи докато не стигне края на файла
		while (is) {
			is >> symbol;
			tape.push_back(symbol);
		}
		is.close();
	}
	else std::cerr << "Cannot open file!";
}


//извежда във файл символите на лентата
void Tape::output(std::string filename)
{

	std::ofstream os;
	os.open(filename);
	// Проверява се дали файлът е отворен.Ако не е, се извежда съобщение за грешка
	if (os.is_open()) {
		// Записват се символите от лентата във файла, докато не се стигне нейният край
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




