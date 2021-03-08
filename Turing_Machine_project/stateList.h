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
	std::vector <stData> getBuffer() const;
	size_t size()const;
	void push(const stData);
	void input(const std::string&);//������� ����������� � ������� ����� �� �� �������� �� ����
	void input(const std::vector<stData>&);//������� ����������� �� ������
	bool isThereAState(std::string);// ��������� ���� ��� ��������� � ���� ���
	stData getStateByName(std::string);//����� ����������� � �������� ���
	void print();//������� �������

};

