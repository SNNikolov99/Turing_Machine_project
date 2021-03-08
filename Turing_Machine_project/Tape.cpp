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
//
//bool Tape::existsNext()
//{
//	return iter != tape.end();
//}
//
//bool Tape::existsPrev()
//{
//	return iter != tape.begin();
//}



void Tape::print() const
{
	for (char c :tape) {
		std::cout << c;
	}
}




/*
void Tape::copy(Tape& other)
{
	
	if (other.start == nullptr) {
		start = nullptr;
	}


	if (start == nullptr) {
		start = other.start;
	}


	tapeNode* newElement = nullptr;
	tapeNode* lastCreated = start;
	tapeNode* curr2 = other.start->next;

	while (curr2 != nullptr) {
		newElement = new tapeNode(curr2->val);
		newElement->previous = lastCreated;
		lastCreated->next = newElement;
		curr2 = curr2->next;
		lastCreated = newElement;
	}

}


void Tape::erase()
{
	if (start == nullptr)return;
	if (start != nullptr && (start->val <= ' ' || start->val > '~'))return;
	else {
		tapeNode* current = start;
		tapeNode* tobeDel = nullptr;
		while (current->next != nullptr) {
			tobeDel = current->next;
			delete current;
			current = tobeDel;

		}
		delete tobeDel;
	}
}


Tape::Tape() {
	start = nullptr;
}

Tape& Tape::operator=(Tape& other)
{
	if (this != &other) {
		this->erase();
		this->copy(other);
	}
	return *this;
}


void Tape::input(std::string filename)
{
	std::ifstream is;
	char symbol;
	is.open(filename);
	
	if (is.is_open()) {

		
		if (start == nullptr) {
			is >> symbol;
			start = new tapeNode(symbol);
			start->next = new tapeNode('~');

		}

		
		tapeNode* current = start->next;
		tapeNode* prev = start;

		
		while (!is.eof()) {
			is >> symbol;
			current->val = symbol;
			current->previous = prev;
			prev = current;
			current = new tapeNode('~');
			prev->next = current;

		}

		is.close();
	}
	else std::cerr << "Cannot open file!";
}

void Tape::push_back(tapeNode* tba)
{
	if (start == nullptr) {
		start = tba;
		return;
	}

	tapeNode* current = start;
	while (current->next) {
		current = current->next;
	}

	current->next = tba;
	tba->previous = current;

}



tapeNode* Tape::inputFromBuffer(std::vector<tapeNode*> buffer)
{
	tapeNode* current = buffer.front();
	start = buffer.front();
	tapeNode* prev = nullptr;
	for (size_t i = 0; i < buffer.size(); i++) {
		prev = current;
		current = current->next;
		current->previous = prev;
	}
	return start;
}


void Tape::output(std::string filename)
{
	tapeNode* current = start;
	std::ofstream os;
	os.open(filename);
	if (os.is_open()) {
		while (current->next != nullptr) {
			os << current->val;
			current = current->next;
		}

		os.close();
	}
	else std::cerr << "Cannot open the file successfully!";
}

tapeNode* Tape::findEnd()
{
	tapeNode* current = start;
	while (current->next) {
		current = current->next;
	}

	return current;
}

void Tape::print()
{
	tapeNode* current = start;
	while (current->next) {
		std::cout << current->val;
		current = current->next;
	}
}

tapeNode* Tape::getStart()
{
	return start;
}


Tape::~Tape()
{
	erase();
}

void Tape::setStart(tapeNode* other)
{
	start = other;
}

*/

