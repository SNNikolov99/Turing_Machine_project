#include "TuringMachine.h"
#include<iostream>

using str = std::string;
using stData = std::pair<std::string, bool>;

TuringMachine::TuringMachine()
{
	cmpSucc = true;
	head = nullptr;
	currentState = { " ",1 };
}


TuringMachine& TuringMachine::operator=(TuringMachine& other)
{
	if (this != &other) {
		tape = other.tape;
		states = other.states;
		head = other.head;
		cmpSucc = other.cmpSucc;
		instructions = other.instructions;
		currentState = other.currentState;
	}
	return* this;
}

TuringMachine::~TuringMachine()
{
	
}

bool TuringMachine::isComplete() {
	return cmpSucc;
}

void TuringMachine::setData(str statesData, str tapeData,str instructionsData)
{
	std::ifstream is1, is2,is3;
	
	is1.open(statesData);
	states.setStates(statesData);
	is1.close();

	is2.open(tapeData);
	//въвеждаме информация за лентата
	tape.input(tapeData);
	is2.close();

	is3.open(instructionsData); 
	instructions.input(instructionsData);
	is3.close();
	
	head = tape.getStart();
	currentState = states.getBuffer().front();
	cmpSucc = false;

}

//TODO: проверка дали моментното състояние е валидно,тоест има го в списъка със състояния.
void TuringMachine::processWithoutOutput()
{
	for (int i = 0; i < instructions.size(); i++) {

		//Ако моментното състояние е крайно,машината да спира работа
		if (currentState.second == 1) {
			cmpSucc = true;
			return;
		}
		else {
			if (!this->states.isThereAState(currentState.first)) {
				std::cerr << "Unknown state detected.Processing will stop.";
				return;
			}
			if (head->val == instructions[i].checkSymbol) {
				//Различни случаи за посоките
				if (instructions[i].direction == 'R') {
					//проверяваме дали следващо място на лентата съществува.Ако не,го създаваме.
					if (head->next != nullptr) {
						head->val = instructions[i].writeNewSymbol;
						head = head->next;
					}
					else {
						head->next = new tapeNode(' ');
						head->val = instructions[i].writeNewSymbol;
						head->next->previous = head;
						head = head->next;

					}
				}

				else if (instructions[i].direction == 'L') {
					//проверяваме дали предшестващо място на лентата съществува.Ако не,го създаваме.
					if (head->previous != nullptr) {
						head->val = instructions[i].writeNewSymbol;
						head = head->previous;
					}
					else {
						head->previous = new tapeNode(' ');
						head->val = instructions[i].writeNewSymbol;
						head->previous->next = head;
						head = head->previous;

					}
				}
				else if (instructions[i].direction == 'N') {
					head->val = instructions[i].writeNewSymbol;
				}
				else {
					std::cerr << "Direction like this does not exist";
					return;
				}
				//Променяме състоянието на следващото ако символът на лентата съвпада с този на командата
				currentState = states.getStateByName(instructions[i].nextStateName);

			}

			else {
				//Копиран код от предишния случай.Проверяваме пак за същите неща.
				if (instructions[i].direction == 'R') {

					if (head->next != nullptr) {
						head->val = instructions[i].writeNewSymbol;
						head = head->next;
					}
					else {
						head->next = new tapeNode(' ');
						head->val = instructions[i].writeNewSymbol;
						head->next->previous = head;
						head = head->next;

					}
				}

				else if (instructions[i].direction == 'L') {

					if (head->previous != nullptr) {
						head->val = instructions[i].writeNewSymbol;
						head = head->previous;
					}
					else {
						head->previous = new tapeNode(' ');
						head->val = instructions[i].writeNewSymbol;
						head->previous->next = head;
						head = head->previous;

					}
				}
				else if (instructions[i].direction == 'N') {
					head->val = instructions[i].writeNewSymbol;
				}
				else {
					std::cerr << "Direction like this does not exist";
					return;
				}
				//Променяме състоянието към следващото ако символът на лентата не съвпада с този на командата
				currentState = states.getStateByName(instructions[i].nextStateNameIfFalse);
			}
		}
	}
	//Ако е изпълнен целият лист с команди и машината не е гръмнала досега значи  приключва работа успешно
	cmpSucc = 1;
}


//обработва лентата като изпълнява правилата от състоянията и я записва във изходен файл
void TuringMachine::proccess(str filename)
{
	this->processWithoutOutput();
	this->tape.output(filename);
}


Tape TuringMachine::returnTape()
{
	return tape;
}

stateList TuringMachine::getStateList()
{
	return states;
}




void TuringMachine::concat(TuringMachine& other)
{
	//обединяваме лентите в една
	
	tapeNode* tbc = nullptr;
	tapeNode* curr = other.tape.getStart();
	tapeNode* prev = this->tape.findEnd();
	
	while (curr) {
		tbc = new tapeNode(curr->val);
		prev->next = tbc;
		tbc->previous = prev;
		tbc = tbc->next;
		curr = curr->next;
	}

	//обединяваме списъците със състояния
	for (int i = 0; i < other.states.size(); i++) {
		this->states.push(other.states[i]);
	}

	//Обединяваме списъците с инструкции
	for (int i = 0; i < other.instructions.size(); i++) {
		this->instructions.push(other.instructions[i]);
	}

	
	
}

void TuringMachine::machineSwitcher(TuringMachine A, TuringMachine B,const std::string instructions)
{
	
	this->processWithoutOutput();

	//Ако мометната машина върне истина,входът се изпълнява върху първата машина ,иначе-върху втората.
	if (this->isComplete()) {
		
		A.processWithoutOutput();
		A.tape.print();
	}
	else {
		B.processWithoutOutput();
		B.tape.print();
	}

}






