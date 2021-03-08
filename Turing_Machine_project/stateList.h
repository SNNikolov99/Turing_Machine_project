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
	std::vector <stData> getBuffer() const;
	size_t size()const;
	void push(const stData);
	void input(const std::string&);//създава състоянията с техните данни те се въвеждат от файл
	void input(const std::vector<stData>&);//извлича състоянията от вектор
	bool isThereAState(std::string);// проверява дали има състояние с това име
	stData getStateByName(std::string);//връща състоянието с подадено име
	void print();//извежда списъка

};

