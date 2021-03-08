#include "rulesList.h"
#include <fstream>
#include <iostream>
#include <cassert>

rulesList::rulesList()
{
}

rulesList& rulesList::operator=(rulesList& other)
{
	if (this != &other) {
		this->list = other.list;
	}
	return *this;
}

rulesList::~rulesList()
{
	list.clear();
}

instruction rulesList::operator[](int n)const
{
	assert(n < list.size());
	return list[n];
}

void rulesList::push(const instruction& newInstruction)
{
	list.push_back(newInstruction);
}

void rulesList::input(const std::string& filename)
{
	std::ifstream is;
	std::string _checkState, _nextStateName, _nextStateNameifFalse;
	char _checkSymbol, _newSymbol, _direction;


	is.open(filename);
	while (!is.eof()) {
		is >> _checkSymbol;
		is >> _checkState;
		is >> _newSymbol;
		is >> _direction;
		is >> _nextStateName;
		list.push_back(*new instruction(_checkSymbol, _checkState, _newSymbol, _direction, _nextStateName));
	}

}

void rulesList::input(const std::vector<instruction>& vec)
{
	list = vec;
}

std::vector<instruction> rulesList::getList() const {
	return list;
}

size_t rulesList::size()const
{
	return list.size();
}

void rulesList::print()const
{
	
	for (int i = 0; i < list.size();i++) {
		std::cout << "("<<list[i].checkSymbol << "," <<list[i].checkState << ","
			<<list[i].writeNewSymbol<< "," <<list[i].direction << ","<<list[i].nextStateName 
			 << ")" << std::endl;
	}
}
