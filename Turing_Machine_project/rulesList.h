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
	void push(const instruction&);
	void input(const std::string&);
	void input(const std::vector<instruction>&);
	std::vector<instruction> getList()const;
	instruction operator[](int)const;
	size_t size()const;
	void print()const;

};


