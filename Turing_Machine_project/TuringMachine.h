#pragma once
#include "Tape.h"
#include <fstream>
#include<vector>
#include "stateList.h"
#include "rulesList.h"

using str = std::string;
using stData = std::pair<std::string, bool>;
/*
Обект на класическа тюринг машина.Имаме лента, от която се чете и на която се записва.
Имаме главата на машината,която чете какво има на лентата и автомат от състояния,който при получаване
на информация от лентата променя състоянието си.

*/
class TuringMachine
{
private:
	//лентата
	Tape tape;
	//иглата
	tapeNode* head;
	//списък от състояния
	stateList states;
	//списък от инструкции
	rulesList instructions;
	//флаг за приключване на машината.Ако се стигнало крайно състояние се връща истина,ако състоянието е halt - лъжа
	bool cmpSucc;
	//мометното състояние на машината
	stData currentState;
	
public:
	TuringMachine();
	TuringMachine& operator= (TuringMachine&);
	~TuringMachine();
	bool isComplete();
	void setData(str,str,str);//вкарва данни за състоянията на машината и за нейната лента
	void proccess(str);//обработва лентата и я връща
	void processWithoutOutput();//само обработва лентата
	Tape returnTape();
	stateList getStateList();

	//идеята тук е че ще обединим една машина с друга без да ги присвояваме към трета
	void concat(TuringMachine&);

	
	/*Изпълнява се моментната Тюринг машина и ако тя върне истина се изпълнява първата 
	ТМ-аргумент на тази функция,иначе - вторият ТМ-аргумент.
	*/
	void machineSwitcher(TuringMachine, TuringMachine,const std::string);

};

