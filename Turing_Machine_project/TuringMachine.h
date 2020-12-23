#pragma once
#include "Tape.h"
#include <fstream>
#include<vector>
#include "stateList.h"
#include "rulesList.h"

using str = std::string;
using stData = std::pair<std::string, bool>;
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
	stData currentState;
	
public:
	TuringMachine();
	TuringMachine& operator= (TuringMachine&);
	~TuringMachine();
	bool isComplete();
	void setData(str,str,str);//������ ����� �� ����������� �� �������� � �� ������� �����
	void proccess(str);//��������� ������� � � �����
	void processWithoutOutput();//���� ��������� �������
	Tape returnTape();
	stateList getStateList();

	//������ ��� � �� �� �������� ���� ������ � ����� ��� �� �� ����������� ��� �����
	void concat(TuringMachine&);

	
	/*��������� �� ���������� ������ ������ � ��� �� ����� ������ �� ��������� ������� 
	��-�������� �� ���� �������,����� - ������� ��-��������.
	*/
	void machineSwitcher(TuringMachine, TuringMachine,const std::string);

};

