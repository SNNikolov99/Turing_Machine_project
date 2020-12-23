#include "rulesList.h"
#include <fstream>
#include <iostream>
#include <cassert>

rulesList::rulesList()
{
}

rulesList::~rulesList()
{
	list.clear();
}

state_rule rulesList::operator[](int n)
{
	assert(n < list.size());
	return list[n];
}

void rulesList::push(const state_rule newState)
{
	list.push_back(newState);
}

void rulesList::input(std::string filename)
{
	std::ifstream is;
	std::string _current, _nextStateName, _nextStateNameifFalse;
	char _checkSymbol, _newSymbol, _direction;


	is.open(filename);
	while (!is.eof()) {
		is >> _current;
		is >> _checkSymbol;
		is >> _newSymbol;
		is >> _direction;
		is >> _nextStateName;
		is >> _nextStateNameifFalse;
		list.push_back(*new state_rule(_current, _checkSymbol, _newSymbol, _direction, _nextStateName, _nextStateNameifFalse));
	}

}

std::vector<state_rule>& rulesList::getList() {
	return list;
}

size_t rulesList::size()
{
	return list.size();
}

void rulesList::print()
{
	
	for (int i = 0; i < list.size();i++) {
		std::cout << "("<<list[i].current<<","<<list[i].checkSymbol << ","
			<<list[i].writeNewSymbol<< "," <<list[i].direction << ","<<list[i].nextStateName 
			<< ","<<list[i].nextStateNameIfFalse << ")" << std::endl;
	}
}
