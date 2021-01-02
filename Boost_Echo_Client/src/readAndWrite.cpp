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
    readAndWrite(string input, string host, short port,) : input(input), host(host), port(port) {}

    void run(){
        string word="";
        int opCode;
        getline(cin, input);
        int i=0;
        while(i < input.size()){
            if(input.at(i) = ' '){
                word = input.substr(0,i);
            }
            i++;
        }
        char bytes[2<<10];

        if
      /*  switch (word) {
            case "ADMINREG": opCode = 1;
            case "STUDENTREG": opCode = 2;
            case 3: word ="LOGIN";
                    opCode = 3;
            case 4: word = "LOGOUT";
                    opCode = 4;
            case 5: word = "COURSEREG";
                    opCode = 5;
            case 6: word = "KDAMCHEK";
                    opCode = 6;
            case 7: word = "COURSESTAT";
                    opCode = 7;
            case 8: word = "STUDENTSTAT";
                    opCode = 8;
            case 9: word = "ISREGISTERED";
                    opCode = 9;
            case 10: word = "UNREGISTER";
                    opCode = 10;
            case 11: word = "MYCOURSES";
                    opCode = 11;*/
        }


    }
}



