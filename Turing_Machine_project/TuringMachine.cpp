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
	//��������� ���������� �� �������
	tape.input(tapeData);
	is2.close();

	is3.open(instructionsData); 
	instructions.input(instructionsData);
	is3.close();
	
	head = tape.getStart();
	currentState = states.getBuffer().front();
	cmpSucc = false;

}

//TODO: �������� ���� ���������� ��������� � �������,����� ��� �� � ������� ��� ���������.
void TuringMachine::processWithoutOutput()
{
	for (int i = 0; i < instructions.size(); i++) {

		//��� ���������� ��������� � ������,�������� �� ����� ������
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
				//�������� ������ �� ��������
				if (instructions[i].direction == 'R') {
					//����������� ���� �������� ����� �� ������� ����������.��� ��,�� ���������.
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
					//����������� ���� ������������ ����� �� ������� ����������.��� ��,�� ���������.
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
				//��������� ����������� �� ���������� ��� �������� �� ������� ������� � ���� �� ���������
				currentState = states.getStateByName(instructions[i].nextStateName);

			}

			else {
				//������� ��� �� ��������� ������.����������� ��� �� ������ ����.
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
				//��������� ����������� ��� ���������� ��� �������� �� ������� �� ������� � ���� �� ���������
				currentState = states.getStateByName(instructions[i].nextStateNameIfFalse);
			}
		}
	}
	//��� � �������� ������ ���� � ������� � �������� �� � �������� ������ �����  ��������� ������ �������
	cmpSucc = 1;
}


//��������� ������� ���� ��������� ��������� �� ����������� � � ������� ��� ������� ����
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
	//����������� ������� � ����
	
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

	//����������� ��������� ��� ���������
	for (int i = 0; i < other.states.size(); i++) {
		this->states.push(other.states[i]);
	}

	//����������� ��������� � ����������
	for (int i = 0; i < other.instructions.size(); i++) {
		this->instructions.push(other.instructions[i]);
	}

	
	
}

void TuringMachine::machineSwitcher(TuringMachine A, TuringMachine B,const std::string instructions)
{
	
	this->processWithoutOutput();

	//��� ��������� ������ ����� ������,������ �� ��������� ����� ������� ������ ,�����-����� �������.
	if (this->isComplete()) {
		
		A.processWithoutOutput();
		A.tape.print();
	}
	else {
		B.processWithoutOutput();
		B.tape.print();
	}

}






