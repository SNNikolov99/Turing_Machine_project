#pragma once
#ifndef TAPE_H
#define TAPE_H

#include<string>
#include<fstream>
#include<vector>


//���������� ������ �� �������,����� �� ��������� �� ���� ������ 
struct tapeNode {
	tapeNode* previous;
	tapeNode* next;
	char val;

	tapeNode() :previous(nullptr), next(nullptr), val(NULL) {};
	tapeNode(char newVal) :previous(nullptr), next(nullptr), val(newVal) {};

};

/*
����������� ������� ���� ������� ������.�� �� ��� ������,� ��� ����� ��������������.
�� �� ��������� ���������,������ ���� ���������� �� ������� ����.��-������ � ��������� ��������������
�� ������.
*/
class Tape
{
private:
	tapeNode* start;
	void copy(Tape&);
	void erase();
public:
	Tape();
	Tape& operator =(Tape&);
	~Tape();
	//set-�� �� ���������� �������
	void setStart(tapeNode*);
	//��������� �� ���������� �� ������� ����
	void input(std::string);
	//����� � �������� �������� �� �����
	tapeNode* inputFromBuffer(std::vector<tapeNode*>);
	//��������� �� ���������� � ������� ����
	void output(std::string);
	//������ ���� �� �������
	tapeNode* findEnd();
	//������� ����������� �� ������� �� ���������
	void print();
	// get-�� �� ���������� ������� 
	tapeNode* getStart();

};
#endif