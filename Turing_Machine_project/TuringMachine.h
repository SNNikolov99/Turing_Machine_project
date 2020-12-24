#pragma once
#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H


#include "Tape.h"
#include <fstream>
#include<vector>
#include "stateList.h"
#include "rulesList.h"

using str = std::string;
using state = std::pair<std::string, bool>;
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
	state currentState;

	void copy(Tape, stateList, rulesList);
	
public:
	TuringMachine();
	TuringMachine(Tape, stateList, rulesList);
	TuringMachine& operator= (TuringMachine&);
	~TuringMachine();
	bool isComplete();
	void setData(str,str,str);//вкарва данни за състоянията на машината и за нейната лента
	void setData(Tape, stateList, rulesList);//вкарва данни за състоянията на машината и за нейната лента
	void proccess(str);//обработва лентата и я връща
	void processWithoutOutput();//само обработва лентата
	Tape returnTape();
	rulesList getInstructionList();
	stateList getStateList();

	//идеята тук е че ще обединим една машина с друга без да ги присвояваме към трета
	void concat(TuringMachine&);

	
	/*Приемат се две индивидуални тюринг машини със собствени ленти състояния и инструкции.
	Функцията представлява разклонение на две тюринг машини относно трета.
	*/
	void machineSwitcher(TuringMachine, TuringMachine);

};
#endif 

