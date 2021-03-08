#include "TuringMachine.h"
#include<iostream>


using str = std::string;
using stData = std::pair<std::string, bool>;

void TuringMachine::copy( Tape& _tape, stateList& _states, rulesList& _instructions)
{
	tape = _tape;
	states = _states;
	instructions = _instructions;
	head = 0;
	currentState = _states[0];
	cmpSucc = false;
}

TuringMachine::TuringMachine()
{
	cmpSucc = true;
	//head = nullptr;
	currentState = { " ",1 };
}

TuringMachine::TuringMachine(Tape _tape, stateList _states, rulesList _instructions)
{
	copy(_tape, _states, _instructions);
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

bool TuringMachine::isComplete()const {
	return cmpSucc;
}

void TuringMachine::setData(const str& statesData,const str& tapeData,const str& instructionsData)
{
	std::ifstream is1, is2,is3;
	
	is1.open(statesData);
	states.input(statesData);
	is1.close();

	is2.open(tapeData);
	//въвеждаме информация за лентата
	tape.input(tapeData);
	is2.close();

	is3.open(instructionsData); 
	instructions.input(instructionsData);
	is3.close();
	
	head = 0;
	currentState = states.getBuffer().front();
	cmpSucc = false;

}

void TuringMachine::setData(Tape& _tape, stateList& _states, rulesList& _instructions)
{
	copy(_tape, _states, _instructions);
}

void TuringMachine::setTape(Tape& _tape)
{
	tape = _tape;
	//*head = _tape.front();
}


void TuringMachine::processWithoutOutput()
{
	for (int i = 0; i < instructions.size(); i++) {

		//Ако моментното състояние е крайно,машината да спира работа
		if (currentState.second == 1) {
			cmpSucc = true;
			return;
		}
		else {
			//Проверяваме  дали моментното състояние е валидно.Ако не е - машината да спира работа.
			if (!this->states.isThereAState(currentState.first)) {
				std::cerr << "Unknown state detected.Processing will stop.";
				return;
			}

			/*Ако символът на главата и моментното състояние съвпадат с тези на моментната инструкция,
			да се извърши преходът.Иначе нищо да не се извършва.
			*/

			if (tape[head] == instructions[i].checkSymbol && currentState.first == instructions[i].checkState) {
				//Различни случаи за посоките

				if (instructions[i].direction == 'R') {
					//проверяваме дали следващо място на лентата съществува.Ако не,го създаваме.
					if (head != tape.size() - 1 ) {
						tape[head] = instructions[i].writeNewSymbol;
						head ++;
					}
					else {
						tape.push_back('~');
						tape[head] = instructions[i].writeNewSymbol;
						head++;

					}
				}

				else if (instructions[i].direction == 'L') {
					//проверяваме дали предшестващо място на лентата съществува.Ако не,го създаваме.
					if (head != 0) {
						tape[head] = instructions[i].writeNewSymbol;
						head --;
					}
					else {
						tape[head] = instructions[i].writeNewSymbol;
						tape.push_front('~');
						head--;

					}
				}
				else if (instructions[i].direction == 'N') {
					tape[head] = instructions[i].writeNewSymbol;
				}
				else {
					std::cerr << "Direction like this does not exist";
					return;
				}
				//Променяме моментното състояние на следващото 
				currentState = states.getStateByName(instructions[i].nextStateName);

			}
		}
	}
	//Ако е изпълнен целият лист с команди и машината не е гръмнала досега значи приключва работа успешно
	cmpSucc = true;
}


//обработва лентата като изпълнява правилата от състоянията и я записва във изходен файл
void TuringMachine::proccess(str filename)
{
	this->processWithoutOutput();
	this->tape.output(filename);
}


Tape TuringMachine::getTape() const
{
	return tape;
}

rulesList TuringMachine::getInstructionList() const
{
	return this->instructions;
}

stateList TuringMachine::getStateList() const
{
	return states;
}




void TuringMachine::concat(TuringMachine& other)
{
	//обединяваме лентите в една
	for (int i = 0; i < other.tape.size(); i++) {
		this->tape.push_back(other.tape[i]);
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

void TuringMachine::machineSwitcher(TuringMachine A, TuringMachine B)
{
	
	this->processWithoutOutput();

	//Ако мометната машина върне истина,входът от инструкции се изпълнява върху първата машина ,иначе-върху втората.
	if (this->isComplete()) {
		A.instructions = this->instructions;
		A.processWithoutOutput();
		A.tape.print();
	}
	else {
		B.instructions = this->instructions;
		B.processWithoutOutput();
		B.tape.print();
	}

}






