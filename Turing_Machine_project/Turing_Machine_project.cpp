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


void multiTapedTest() {
    stateList states;
    states.setStates("inputStates.txt");
    rulesList instructions;
    instructions.input("inputRules1.txt");
    std::vector<Tape> tapes;

    Tape tape1, tape2, tape3;
    tapes.push_back(tape1);
    tapes.push_back(tape2);
   // tapes.push_back(tape3);

    tapes[0].input("inputTape1.txt");
    tapes[1].input("inputTape2.txt");
    //tapes[2].input("inputTape3.txt");


    multiTapedTM A(tapes,states,instructions);

    TuringMachine res = A.as_TuringMachine();
    res.returnTape().print();
}

/*TODO: 
-Тествай още малко TMswitcher
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
    multiTapedTest();
}

