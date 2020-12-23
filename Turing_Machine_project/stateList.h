#pragma once
#include<iostream>
#include<vector>


using stData = std::pair<std::string, bool>;

class stateList
{
	//буфер в който се съхраняват състоянията,като се въведат.
	//В него ще се съхраняват двойка от низове и флагове.Пръвото е името на състоянието,а второто - флаг дали е крайно или не.
	std::vector<stData> stateBuffer;

public:
	stateList();
	~stateList();
	stData operator[](int) const;
	std::vector <stData> getBuffer();
	size_t size();
	void push(const stData);
	void setStates(std::string);//създава състоянията с техните данни те се въвеждат от файл
	bool isThereAState(std::string);// проверява дали има състояние с това име
	stData getStateByName(std::string);//връща състоянието с подадено име
	void printList();//извежда списъка

};

