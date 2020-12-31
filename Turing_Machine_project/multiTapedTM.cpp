#include "multiTapedTM.h"

multiTapedTM::multiTapedTM()
{
	cmpSucc = false;
	head = nullptr;
}

multiTapedTM::multiTapedTM(std::vector<Tape>& _tapes, stateList& _states, rulesList& _rules)
{
	listOfTapes = _tapes;
	this->states = _states;
	this->instructions = _rules;
	currentState = _states[0];
	this->cmpSucc = false;
}

multiTapedTM::~multiTapedTM()
{
	listOfTapes.~vector();
	head = nullptr;
	states.~stateList();
	instructions.~rulesList();

}
//Еднолентовата машина на тюринг може да се получим като слепим всичките ленти на многолентовата в една
TuringMachine multiTapedTM::as_TuringMachine()
{
	if (listOfTapes.empty()) {
		return this->Returned;
	}

	if (listOfTapes.size() == 1) {
		Returned.setTape(listOfTapes[0]);
		return Returned;
	}

	/*
		Обединяваме целия вектор от ленти в една лента.Трябват ни три адреса на клетки:
		-един за създаване на нова клетка
		-един за следене на моментната клетка в обединената лента
		-един за следене на моментната клетка в моментната лента

		Докато сме в една моментна лента,създаваме нови клетки с данните от тази лента и ги поставяме към първата лента,
		като навързваме клетките с преходи.Извършваме това действие докато не свършат лентите.
	*/

	
	tapeNode* tbc = nullptr;

	for (size_t i = 1; i < listOfTapes.size(); i++) {
		tapeNode* inTape = listOfTapes[i].getStart();
		while (inTape->next) {
			tbc = new tapeNode(inTape->val);
			listOfTapes[0].push_back(tbc);
			inTape = inTape->next;
		}

	}

	//Началото на лентата та еднолентовата машина е началото на първата лента от вектора с ленти
	Returned.setTape(listOfTapes[0]);
	return Returned;
}
