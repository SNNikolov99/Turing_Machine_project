#include "Tape.h"
#include <iostream>
#include <cassert>


Tape::Tape()
{
	currentNode = ' ';
}

Tape::Tape(const std::string& str)
{
	this->input_from_string(str);
	//iter = this->tape.begin();
	//currentNode = *++iter;
}

Tape& Tape::operator=(Tape& other)
{
	if (this != &other) {
		this->tape = other.tape;
		this->currentNode = other.currentNode;
	}
	return *this;
}

Tape::~Tape()
{
}

void Tape::input(const std::string& filename)
{
	std::ifstream is;
	is.open(filename);
	char symbol;

	if (is.is_open()) {
		while (is.get(symbol)) {
			//if the symbol is different from whitespace,push in the tape
			if (symbol != ' ') {
				tape.push_back(symbol);
			}
		}
		is.close();
	}
	else std::cerr << "Cannot open file!";

	iter = tape.begin();
	currentNode = tape.front();
}

void Tape::input_from_string(const std::string& str)
{
	for (char c : str) {
		tape.push_back(c);
	}
}

void Tape::push_back(const char& c)
{
	tape.push_back(c);
}

void Tape::push_front(const char& c)
{
	tape.push_front(c);
}

char& Tape::operator[](const int& index) 
{
	assert(index < tape.size());
	std::list<char>::iterator it = tape.begin();
	for (int i = 0; i < index; i++) {
		++it;
	}
	return *it;
}

void Tape::output(const std::string& filename)const
{
	std::ofstream os;
	os.open(filename);
	if (os.is_open()) {
		for (char c: tape) {
			os << c;
		}
		os.close();
	}
	else std::cerr << "Cannot open the file successfully!";
}

char Tape::front() const
{
	return tape.front();
}

char Tape::end() const
{
	return tape.back();
}

char Tape::getCurrentNode() const
{
	return currentNode;
}

size_t Tape::size() const
{
	return tape.size();
}

void Tape::left()
{
	if (iter != tape.begin()) {
		currentNode = *--iter;
	}
	else {
		std::cerr << "No such element exists.";
		return;
	}
}

void Tape::right()
{
	if (iter != tape.end()) {
		currentNode = *++iter;
	}
	else {
		std::cerr << "No such element exists.";
		return;
	}
}

char Tape::next() 
{
	if (iter != tape.end()) {
		currentNode = *++iter;
		return currentNode;
	}
	else {
		std::cout << std::endl << "No such element exists.";
		return NULL;
	}
}

char Tape::prev()
{
	if (iter != tape.begin()) {
		currentNode = *--iter;
		return currentNode;
	}
	else {
		std::cout<< std::endl << "No such element exists." ;
		return NULL;
	}
}



void Tape::print() const
{
	for (char c :tape) {
		std::cout << c;
	}
}

