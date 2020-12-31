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
//������������� ������ �� ������ ���� �� �� ������� ���� ������ �������� ����� �� �������������� � ����
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
		����������� ����� ������ �� ����� � ���� �����.������� �� ��� ������ �� ������:
		-���� �� ��������� �� ���� ������
		-���� �� ������� �� ���������� ������ � ����������� �����
		-���� �� ������� �� ���������� ������ � ���������� �����

		������ ��� � ���� �������� �����,��������� ���� ������ � ������� �� ���� ����� � �� ��������� ��� ������� �����,
		���� ���������� �������� � �������.���������� ���� �������� ������ �� ������� �������.
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

	//�������� �� ������� �� ������������� ������ � �������� �� ������� ����� �� ������� � �����
	Returned.returnTape().setStart (listOfTapes[0]. getStart() );
	return Returned;
}
