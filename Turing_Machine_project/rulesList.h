#pragma once
#include <string>
#include <vector>


//идея : (S,0,1,L,A,B)
struct state_rule 
{
	using str = std::string;

	str current;
	char checkSymbol;
	char writeNewSymbol;//записва нов символ под иглата
	char direction;//мести иглата наляво или надясно
	str nextStateName;//новото състояние ако правилото върне истина
	str nextStateNameIfFalse;//новото състояние ако правилото върне лъжа
	
	state_rule(str _current, char _check, char _write, char _dir, str _nextTrue, str _nextFalse) :
		current(_current), checkSymbol(_check), writeNewSymbol(_write),
		direction(_dir), nextStateName(_nextTrue), nextStateNameIfFalse(_nextFalse) {};

};

class rulesList{
private:
	std::vector<state_rule> list;

public:
	rulesList();
	~rulesList();
	state_rule operator[](int);
	void push(const state_rule);
	void input(std::string);
	void print();
	std::vector<state_rule>& getList();
	size_t size();

};

