#pragma once

#include <string>
#include <vector>
#include "instruction.h"


class rulesList{
private:
	std::vector<instruction> list;

public:
	rulesList();
	rulesList& operator =(rulesList&);
	~rulesList();
	instruction operator[](int);
	void push(const instruction&);
	void input(const std::string&);
	void print();
	std::vector<instruction> getList()const;
	size_t size()const;

};


