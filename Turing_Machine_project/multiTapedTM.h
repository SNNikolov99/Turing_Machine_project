#pragma once
#ifndef MULTITAPEDTM_H
#define MULTITAPEDTM_H

#include "TuringMachine.h"
#include <vector>

/*
������ ������ � ��������� �����
*/
class multiTapedTM
{
private:
	//����������� �� �����
	std::vector<Tape> listOfTapes;
	//�������
	tapeNode* head;
	//������ �� ���������
	stateList states;
	//������ �� ����������
	rulesList instructions;
	//���� �� ����������� �� ��������.��� �� �������� ������ ��������� �� ����� ������,��� ����������� � halt - ����
	bool cmpSucc;
	//��������� ��������� �� ��������
	state currentState;
	TuringMachine Returned;
public:
	multiTapedTM();
	multiTapedTM(std::vector<Tape>&, stateList&, rulesList&);
	~multiTapedTM();
	TuringMachine as_TuringMachine();//�������� ������������ ������ �� ������ � �����������

};

#endif // !MULTITAPEDTM_H

