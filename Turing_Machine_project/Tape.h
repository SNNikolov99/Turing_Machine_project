#pragma once
#include<string>
#include<fstream>
#include<vector>
#include<iterator>
#include <list>
//#include "tapeNode.h"



/*
����������� ������� ���� ������� ������.�� �� ��� ������,� ��� ����� ��������������.
�� �� ��������� ���������,������ ���� ���������� �� ������� ����.��-������ � ��������� ��������������
�� ������.
*/
class Tape
{
private:
	std::list<char> tape;
	std::list<char>::iterator iter;
	char currentNode;
public:
	Tape();
	Tape(const std::string&);
	Tape& operator =(Tape&);
	~Tape();
	
	//��������� �� ���������� �� ������� ����
	void input(const std::string&);
	//��������� �� ���
	void input_from_string(const std::string&);
	//�������� �� ������ �����
	void push_back(const char&);
	//�������� �� ������ ������
	void push_front(const char&);
	//������ �� �������
	char& operator[](const int&);
	//��������� �� ���������� � ������� ����
	void output(const std::string&) const;
	//����� �������� �� �������
	char front()const;
	//����� ���� �� �������
	char end()const;
	//����� ���������� ������
	char getCurrentNode()const;
	//����� ������� �� �������
	size_t size()const;
	//����� ��������� �� ���������� ������ ������
	void left();
	//����� ��������� �� ���������� ������ �������
	void right();
	//����� ���������� ������� � �������
	char next();
	//����� ���������� ������� � �������
	char prev();
	//������� ����������� �� ������� �� ���������
	void print()const;

	

};


