#pragma once
#include<string>

//���� : (S,0,1,L,A,B)
struct instruction
{
	using str = std::string;


	char checkSymbol;
	str checkState; //���������� � ��� �������� �� ���������� ���������
	char writeNewSymbol;//������� ��� ������ ��� ������
	char direction;//����� ������ ������ ��� �������
	str nextStateName;//���������� ��������� 


	instruction(char _check, str _checkState, char _write, char _dir, str _nextTrue) :
		checkState(_checkState), checkSymbol(_check), writeNewSymbol(_write),
		direction(_dir), nextStateName(_nextTrue) {};

};