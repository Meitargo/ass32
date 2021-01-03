//
// Created by spl211 on 02/01/2021.
//

#include <readAndWrite.h>
#include <iostream>
#include <thread>
#include <fstream>

using namespace std;

using std::cin;

class readAndWrite{
private:
    string input;
    const string host;//ip
    const short port;
    //tcp::socket socket;
public:
    readAndWrite(string input, string host, short port) : input(input), host(host), port(port) {}

    void run(){
        string word="";
        int opCode;
        string withoutOpCode="";
        getline(cin, input);
        int i=0;

        while(i < input.size()){
            if(input.at(i) = ' '){
                word = input.substr(0,i);
                withoutOpCode = input.substr(i+1, input.size());
            }
            i++;
        }

        if(input.substr() == "ADMINREG"){

        }


    }
}



