#pragma once
#ifndef MULTITAPEDTM_H
#define MULTITAPEDTM_H

#include "TuringMachine.h"
#include <vector>

/*
Тюринг машина с множество ленти
*/
class multiTapedTM
{
private:
	//множеството от ленти
	std::vector<Tape> listOfTapes;
	//главата
	tapeNode* head;
	//списък от състояния
	stateList states;
	//списък от инструкции
	rulesList instructions;
	//флаг за приключване на машината.Ако се стигнало крайно състояние се връща истина,ако състоянието е halt - лъжа
	bool cmpSucc;
	//мометното състояние на машината
	state currentState;
public:
	multiTapedTM();
	~multiTapedTM();
	TuringMachine as_TuringMachine();//Превръща многолентова машина на тюринг в еднолентова

};

#endif // !MULTITAPEDTM_H

