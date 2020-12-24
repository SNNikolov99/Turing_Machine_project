#pragma once
#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H


#include "Tape.h"
#include <fstream>
#include<vector>
#include "stateList.h"
#include "rulesList.h"

using str = std::string;
using state = std::pair<std::string, bool>;
/*
����� �� ���������� ������ ������.����� �����, �� ����� �� ���� � �� ����� �� �������.
����� ������� �� ��������,����� ���� ����� ��� �� ������� � ������� �� ���������,����� ��� ����������
�� ���������� �� ������� ������� ����������� ��.

*/
class TuringMachine
{
private:
	//�������
	Tape tape;
	//������
	tapeNode* head;
	//������ �� ���������
	stateList states;
	//������ �� ����������
	rulesList instructions;
	//���� �� ����������� �� ��������.��� �� �������� ������ ��������� �� ����� ������,��� ����������� � halt - ����
	bool cmpSucc;
	//��������� ��������� �� ��������
	state currentState;

	void copy(Tape, stateList, rulesList);
	
public:
	TuringMachine();
	TuringMachine(Tape, stateList, rulesList);
	TuringMachine& operator= (TuringMachine&);
	~TuringMachine();
	bool isComplete();
	void setData(str,str,str);//������ ����� �� ����������� �� �������� � �� ������� �����
	void setData(Tape, stateList, rulesList);//������ ����� �� ����������� �� �������� � �� ������� �����
	void proccess(str);//��������� ������� � � �����
	void processWithoutOutput();//���� ��������� �������
	Tape returnTape();
	rulesList getInstructionList();
	stateList getStateList();

	//������ ��� � �� �� �������� ���� ������ � ����� ��� �� �� ����������� ��� �����
	void concat(TuringMachine&);

	
	/*������� �� ��� ������������ ������ ������ ��� ��������� ����� ��������� � ����������.
	��������� ������������ ����������� �� ��� ������ ������ ������� �����.
	*/
	void machineSwitcher(TuringMachine, TuringMachine);

};
#endif 

