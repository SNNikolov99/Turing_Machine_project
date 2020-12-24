#pragma once
#ifndef RULESLIST_H
#define RULESLIST_H

#include <string>
#include <vector>


//идея : (S,0,1,L,A,B)
struct instruction
{
	using str = std::string;

	
	char checkSymbol;
	str checkState; //Променлива с цел проверка на моментното състояние
	char writeNewSymbol;//записва нов символ под иглата
	char direction;//мести иглата наляво или надясно
	str nextStateName;//следващото състояние 
	
	
	instruction( char _check,str _checkState, char _write, char _dir, str _nextTrue) :
		checkState(_checkState), checkSymbol(_check), writeNewSymbol(_write),
		direction(_dir), nextStateName(_nextTrue){};

};

class rulesList{
private:
	std::vector<instruction> list;

public:
	rulesList();
	rulesList& operator =(rulesList&);
	~rulesList();
	instruction operator[](int);
	void push(const instruction);
	void input(std::string);
	void print();
	std::vector<instruction>& getList();
	size_t size();

};
#endif 

