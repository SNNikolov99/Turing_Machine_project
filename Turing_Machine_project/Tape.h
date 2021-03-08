#pragma once
#include<string>
#include<fstream>
#include<vector>
#include<iterator>
#include <list>
//#include "tapeNode.h"



/*
Представяме лентата като свързан списък.Тя ще има начало,с цел лесно инициализиране.
Ще се разширява динамично,докато чете информация от текстов файл.По-надолу е спомената функциалността
на обекта.
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
	
	//Въвеждане на информация от текстов файл
	void input(const std::string&);
	//Въвеждане от низ
	void input_from_string(const std::string&);
	//добавяне на символ отзад
	void push_back(const char&);
	//добавяне на символ отпред
	void push_front(const char&);
	//достъп до елемент
	char& operator[](const int&);
	//извеждане на информация в текстов файл
	void output(const std::string&) const;
	//връща началото на лентата
	char front()const;
	//връща края на лентата
	char end()const;
	//връща моментната клетка
	char getCurrentNode()const;
	//връща размера на лентата
	size_t size()const;
	//мести указателя за моментната клетка наляво
	void left();
	//мести указателя за моментната клетка надясно
	void right();
	//връща следващият елемент в списъка
	char next();
	//връща предишният елемент в списъка
	char prev();
	//проверява дали следващият елемент съществува
	//bool existsNext();
	//проверява дали предишният елемент съществува
	//bool existsPrev();
	//извежда инормацията на лентата на конзолата
	void print()const;

	

};

/*

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
	//set-ър за стартовата позиция
	void setStart(tapeNode*);
	//Въвеждане на информация от текстов файл
	void input(std::string);
	void push_back(tapeNode*);
	//взима и навързва клетките от буфер
	tapeNode* inputFromBuffer(std::vector<tapeNode*>);
	//извеждане на информация в текстов файл
	void output(std::string);
	//намира края на лентата
	tapeNode* findEnd();
	//извежда инормацията на лентата на конзолата
	void print();
	// get-ър за стартовата позиция 
	tapeNode* getStart();

};
*/
