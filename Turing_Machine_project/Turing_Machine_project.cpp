// Turing_Machine_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Tape.h"
#include"stateList.h"
#include "rulesList.h"
#include "TuringMachine.h"


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
    T.proccess("TMoutput.txt");
}

void ConcTest() {
    TuringMachine A, B;
    A.setData("inputStates.txt","inputTape1.txt", "inputRules1.txt");
    B.setData("inputStates2.txt","inputTape2.txt","inputRules2.txt");
    A.concat(B);
    A.proccess("TMoutput.txt");
    A.getStateList().printList();
    
   
 
    
}

void TMswitcher() {
    TuringMachine A, B;
    
  //  A.machineSwitcher(B, C,key, "inputStates2.txt", "inputFalseStates1.txt", "inputStates.txt", "inputFalseStates.txt",
   //     "inputStates2.txt", "inputFalseStates1.txt", "inputTape1.txt");
}


/*TODO: 
-Направи още тестови случаи.Само няколко тестови файла не са достатъчни

*/
int main()
{
   // tapeTest();
    //stateTest();
    //rulesTest();
    //TMTest();
    tapeRevTest();
   //ConcTest();
  // TMswitcher();
}

