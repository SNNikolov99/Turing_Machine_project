#include "multiTapedTM.h"

multiTapedTM::multiTapedTM()
{
	cmpSucc = false;
	head = nullptr;
}

multiTapedTM::multiTapedTM(std::vector<Tape>& _tapes, stateList& _states, rulesList& _instructions)
{
	this->listOfTapes = _tapes;
	this->states = _states;
	this->instructions = _instructions;
	cmpSucc = false;
	currentState = _states[0];
}

multiTapedTM::~multiTapedTM()
{
	/*listOfTapes.~vector();
	head = nullptr;
	states.~stateList();
	instructions.~rulesList();*/

}
//������������� ������ �� ������ ���� �� �� ������� ���� ������ �������� ����� �� �������������� � ����
TuringMachine multiTapedTM::as_TuringMachine()
{
	//TuringMachine Returned;
	Tape concTape;
	Returned.setData(concTape, this->states, this->instructions);
	
	
	if (listOfTapes.empty()) {
		Returned.returnTape().setStart(nullptr);

		return Returned;
	}

	if (listOfTapes.size() == 1) {
		Returned.setTape(listOfTapes[0]);
		return Returned;
	}

	/*
		����������� ����� ������ �� ����� � ���� �����.������� �� ��� ������ �� ������:
		-���� �� ��������� �� ���� ������
		-���� �� ������� �� ���������� ������ � ����������� �����
		-���� �� ������� �� ���������� ������ � ���������� �����

		������ ��� � ���� �������� �����,��������� ���� ������ � ������� �� ���� ����� � �� ��������� ��� ������� �����,
		���� ���������� �������� � �������.���������� ���� �������� ������ �� ������� �������.
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

	//�������� �� ������� �� ������������� ������ � �������� �� ������� ����� �� ������� � �����
	Returned.setTape(listOfTapes[0]);
	return Returned;
}
