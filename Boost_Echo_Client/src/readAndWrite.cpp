//
// Created by spl211 on 02/01/2021.
//

#include "../include/readAndWrite.h"
#include <iostream>
#include <thread>
#include <fstream>


using namespace std;

using std::cin;

    //const string host;//ip
    //const short port = 0;
    ConnectionHandler *connectionHandler;
    bool *terminate;

    readAndWrite::readAndWrite(ConnectionHandler &connectionHandler, bool &terminate) : connectionHandler(connectionHandler), terminate(terminate){}

    void readAndWrite::run(){
        string input="";
        string word="";
        short opCode;
        string withoutOpCode="";
        getline(cin, input);
        int i=0;

        while(i < input.size() && input.at(i) != ' ' ) {
            i++;
        }

         word = input.substr(0, i);

        if(word == "ADMINREG")
            opCode =1;
        else if(word == "STUDENTREG")
            opCode = 2;
        else if(word == "LOGIN")
            opCode = 3;
        else if(word == "LOGOUT")
            opCode = 4;
        else if(word == "COURSEREG")
            opCode = 5;
        else if(word == "KDAMCHECK")
            opCode = 6;
        else if(word == "COURSESTAT")
            opCode = 7;
        else if(word == "STUDENTSTAT")
            opCode = 8;
        else if(word == "ISREGISTERED")
            opCode = 9;
        else if(word == "UNREGISTER")
            opCode = 10;
        else if(word == "MYCOURSES")
            opCode = 11;


        if(opCode!=4 && opCode!=11){
            withoutOpCode = input.substr(i + 1, input.size());
        }

        //read the opCode from keyBoard
        if(withoutOpCode.length() == 1){
            withoutOpCode = '0' + withoutOpCode;
        }

        int len;
        if(opCode == 1 || opCode ==2 || opCode ==3){
            i=0;
            while(i < withoutOpCode.size()){
                if(withoutOpCode.at(i) == ' '){
                   withoutOpCode.at(i) = '\0';
                }
                i++;
            }
            len = 3+withoutOpCode.length();
        }

        if(opCode ==5 || opCode ==6 ||opCode ==7 || opCode ==9 || opCode==10){
            len = 2+withoutOpCode.length();
        }

        if(opCode==8){
            len = 3+withoutOpCode.length();
        }

        if(opCode==4 |opCode ==11){
            len =2;
        }
        char opCodeByte[len];


        if(!connectionHandler.connect()){
            std::cerr<< "Cannot connect " << endl;
        }

        else{
            cout << opCode << endl;
            connectionHandler.shortToBytes(opCode, opCodeByte);
            int i=0;
            int j=2;

            while(i<withoutOpCode.length()){
                cout<< withoutOpCode[i] << endl;
                opCodeByte[j] = withoutOpCode.at(i);
                i++;
                j++;
            }

            if(opCode!=4 &&opCode!=11){
                opCodeByte[j] = '\0';
            }

            //send the message to server as bytes

            connectionHandler.sendBytes(opCodeByte,len);
        }

    }




