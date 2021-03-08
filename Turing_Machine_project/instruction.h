#pragma once
#include<string>

//идея : (S,0,1,L,A,B)
struct instruction
{
	using str = std::string;


	char checkSymbol;
	str checkState; //Променлива с цел проверка на моментното състояние
	char writeNewSymbol;//записва нов символ под иглата
	char direction;//мести иглата наляво или надясно
	str nextStateName;//следващото състояние 


	instruction(char _check, str _checkState, char _write, char _dir, str _nextTrue) :
		checkState(_checkState), checkSymbol(_check), writeNewSymbol(_write),
		direction(_dir), nextStateName(_nextTrue) {};

};