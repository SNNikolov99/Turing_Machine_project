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
	stateList(std::vector<stData>&);
	~stateList();
	void push(const stData);
	void input(const std::string&);//������� ����������� � ������� ����� �� �� �������� �� ����
	void input(const std::vector<stData>&);//������� ����������� �� ������
	stData getStateByName(std::string);//����� ����������� � �������� ���
	size_t size()const;
	stData operator[](int) const;
	std::vector <stData> getBuffer() const;
	bool isThereAState(std::string);// ��������� ���� ��� ��������� � ���� ���
	void print()const;//������� �������

};

