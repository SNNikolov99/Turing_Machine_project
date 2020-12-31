#pragma once
#ifndef TAPE_H
#define TAPE_H

#include<string>
#include<fstream>
#include<vector>


//дефинираме клетка на лентата,която ще съхранява по един символ 
struct tapeNode {
	tapeNode* previous;
	tapeNode* next;
	char val;

	tapeNode() :previous(nullptr), next(nullptr), val(NULL) {};
	tapeNode(char newVal) :previous(nullptr), next(nullptr), val(newVal) {};

};

/*
Представяме лентата като свързан списък.Тя ще има начало,с цел лесно инициализиране.
Ще се разширява динамично,докато чете информация от текстов файл.По-надолу е спомената функциалността
на обекта.
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
	//set-ър за стартовата позиция
	void setStart(tapeNode*);
	//Въвеждане на информация от текстов файл
	void input(std::string);
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
#endif