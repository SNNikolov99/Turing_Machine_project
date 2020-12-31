#include "multiTapedTM.h"

multiTapedTM::multiTapedTM()
{
	cmpSucc = false;
	head = nullptr;
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
	TuringMachine Returned;
	
	if (listOfTapes.empty()) {
		Returned.getStateList() = this->states;
		Returned.getInstructionList() = this->instructions;
		Returned.returnTape().setStart(nullptr);

		return Returned;
	}

	if (listOfTapes.size() == 1) {
		Returned.setData(listOfTapes[0], this->states, this->instructions);
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

	tapeNode* current = listOfTapes[0].findEnd();
	tapeNode* tbc = nullptr;

	for (size_t i = 1; i < listOfTapes.size(); i++) {

		tapeNode* inTape = listOfTapes[i].getStart();
		while (inTape->next) {
			tbc = new tapeNode(inTape->val);
			current->next = tbc;
			tbc->previous = current;
			current = current->next;
			tbc = tbc->next;
			inTape = inTape->next;
		}

	}

	//Началото на лентата та еднолентовата машина е началото на първата лента от вектора с ленти
	Returned.returnTape().setStart (listOfTapes[0]. getStart() );
	return Returned;
}
