// Turing_Machine_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Tape.h"
#include"stateList.h"
#include "rulesList.h"
#include "TuringMachine.h"
#include "multiTapedTM.h"


void tapeTest() {
    Tape T;
    T.input("inputTape1.txt");
    T.output("outputTape1.txt");
    T.print();
}
void stateTest() {
    stateList L;
    L.setStates("inputStates.txt");
   // L.setFalseStates("inputFalseStates1.txt");
    L.printList();
}

void rulesTest(){
    rulesList r;
    r.input("rulesTest.txt");
    r.print();
}

void TMTest() {
    TuringMachine T;
    T.setData( "inputStates.txt","inputTape1.txt", "inputRules1.txt");
    T.proccess("TMoutput.txt");
    
}

void tapeRevTest() {
    TuringMachine T;
    T.setData("inputStates.txt", "inputTape1.txt", "inputRulesRev.txt");
 //   T.proccess("TMoutput.txt");
    T.returnTape().print();
    
}

void ConcTest() {
    TuringMachine A, B;
    A.setData("inputStates.txt","inputTape1.txt", "inputRules1.txt");
    B.setData("inputStates2.txt","inputTape2.txt","inputRules2.txt");
    A.concat(B);
    
    A.returnTape().print();
}

void TMswitcher() {
    TuringMachine A, B, C;
    A.setData("inputStates.txt", "inputTape1.txt", "inputRules1.txt");
    B.setData("inputStates2.txt", "inputTape2.txt", "inputRules2.txt");
    C.setData("inputStates3.txt", "inputTape3.txt", "inputRules1.txt");
    C.machineSwitcher(A, B);
    
}

void multiTaped() {
    std::vector<Tape> tapes;
    stateList states;
    rulesList instructions;

    states.setStates("inputStates.txt");
    instructions.input("inputRules1.txt");

    Tape a, b, c;
    tapes.push_back(a);
    tapes.push_back(b);
    tapes.push_back(c);

    tapes[0].input("inputTape1.txt");
    tapes[1].input("inputTape2.txt");
    tapes[2].input("inputTape3.txt");

    multiTapedTM A(tapes, states, instructions);
    TuringMachine B = A.as_TuringMachine();
    B.returnTape().print();


}



/*TODO: 
-Направи клас за многолентова машина на Тюринг.Нека да има същите член данни както еднолентовата машина на Тюринг,
 но tape да се замени с vector<tape>.Преобразуването да става чрез слепването на всички ленти в една.

-Тествай още малко TMswitcher
-Добави възможността една тюринг машина да работи върху някаква лента подадена като вход

*/
int main()
{
    //tapeTest();
    //stateTest();
    //rulesTest();
    //TMTest();
    //tapeRevTest();
    //ConcTest();
   //TMswitcher();
    multiTaped();
}

