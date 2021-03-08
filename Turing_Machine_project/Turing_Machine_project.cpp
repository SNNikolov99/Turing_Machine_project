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
    std::cout << "The data of the tape is: ";
    T.print();
    std::cout << std::endl;
    std::cout << "The char on the current node is: "<<T.getCurrentNode() << std::endl;
    std::cout << "The previous one is: " << T.prev() << std::endl;
   
    //T.right();
    std::cout << "The next one is: " << T.next() << std::endl;;
    //T.right();
    std::cout << "The next one is: " << T.next() << std::endl;;
    //T.left();
    std::cout << "The previous one is: " << T.prev() << std::endl;;
    std::cout << "the tape from the string is: ";
    Tape A;
    A.input_from_string("HelloFookers");
    A.print();
    std::cout <<std::endl<< "=============="<<std::endl;
    char c = A[4];
    std::cout << c;


}
void stateTest() {
    stateList L;
    L.input("inputStates.txt");
    L.print();
}

void rulesTest(){
    rulesList r;
    r.input("inputRules1.txt");
    r.print();
}


void TMTest() {
    TuringMachine T;
    T.setData( "inputStates.txt","inputTape1.txt", "inputRules1.txt");
    T.proccess("TMoutput.txt");
    T.getTape().print();
    
}

void tapeRevTest() {
    TuringMachine T;
    T.setData("inputStates.txt", "inputTape1.txt", "inputRulesRev.txt");
    T.proccess("TMoutput.txt");
    T.getTape().print();
    
}

void ConcTest() {
    TuringMachine A, B;
    A.setData("inputStates.txt","inputTape1.txt", "inputRules1.txt");
    B.setData("inputStates2.txt","inputTape2.txt","inputRules2.txt");
    A.concat(B);
    
    A.getTape().print();
}

void TMswitcher() {
    TuringMachine A, B, C;
    A.setData("inputStates.txt", "inputTape1.txt", "inputRules1.txt");
    B.setData("inputStates2.txt", "inputTape2.txt", "inputRules2.txt");
    C.setData("inputStates3.txt", "inputTape3.txt", "inputRules1.txt");
    C.machineSwitcher(A, B);
    
}
//
//void multiTaped() {
//    std::vector<Tape> tapes;
//    stateList states;
//    rulesList instructions;
//
//    states.setStates("inputStates.txt");
//    instructions.input("inputRules1.txt");
//
//    Tape a, b, c;
//    tapes.push_back(a);
//    tapes.push_back(b);
//    tapes.push_back(c);
//
//    tapes[0].input("inputTape1.txt");
//    tapes[1].input("inputTape2.txt");
//    tapes[2].input("inputTape3.txt");
//
//    multiTapedTM A(tapes, states, instructions);
//    TuringMachine B = A.as_TuringMachine();
//    B.returnTape().print();
//
//
//}




int main()
{
    //tapeTest();
    //stateTest();
    //rulesTest();
    //TMTest();
    //tapeRevTest();
    //ConcTest();
    TMswitcher();
    //multiTaped();
}

