#pragma once
#include<iostream>
#include<vector>


using stData = std::pair<std::string, bool>;

class stateList
{
	//����� � ����� �� ���������� �����������,���� �� �������.
	//� ���� �� �� ���������� ������ �� ������ � �������.������� � ����� �� �����������,� ������� - ���� ���� � ������ ��� ��.
	std::vector<stData> stateBuffer;

public:
	stateList();
	~stateList();
	stData operator[](int) const;
	std::vector <stData> getBuffer();
	size_t size();
	void push(const stData);
	void setStates(std::string);//������� ����������� � ������� ����� �� �� �������� �� ����
	bool isThereAState(std::string);// ��������� ���� ��� ��������� � ���� ���
	stData getStateByName(std::string);//����� ����������� � �������� ���
	void printList();//������� �������

};

