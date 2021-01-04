//
// Created by spl211 on 02/01/2021.
//

#include "../include/readAndWrite.h"
#include <iostream>
#include <thread>
#include <fstream>
#include "../include/connectionHandler.h"


using namespace std;

using std::cin;

    const string host;//ip
    const short port = 0;


    readAndWrite::readAndWrite(string host, short port) : host(host), port(port) {}

    void readAndWrite::run(){
        string input="";
        string word="";
        short opCode;
        string withoutOpCode="";
        getline(cin, input);
        int i=0;

        while(i < input.size()) {
            if (input.at(i) = ' ') {
                word = input.substr(0, i);
                withoutOpCode = input.substr(i + 1, input.size());
            }
            i++;
        }

        //read the opCode from keyBoard
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


        if(opCode == 1 || opCode == 2 || opCode ==3){
            i=0;
            while(i < withoutOpCode.size()){
                if(withoutOpCode.at(i) = ' '){
                   withoutOpCode.at(i) = '/0';
                }
                i++;
            }
        }

        std::string s = std::to_string(opCode);
        const string myString = s + withoutOpCode;

        ConnectionHandler connectionHandler(host,port);
        if(!connectionHandler.connect()){
            std::cerr<< "Cannot connect to" << host<< ":" << port << std::endl;
        }
        else{
            //send the message to server as bytes
            connectionHandler.sendBytes(myString.c_str(),myString.length());
        }

    }




