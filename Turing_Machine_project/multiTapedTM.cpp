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
//������������� ������ �� ������ ���� �� �� ������� ���� ������ �������� ����� �� �������������� � ����
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
