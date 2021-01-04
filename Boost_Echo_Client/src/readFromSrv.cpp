//
// Created by spl211 on 04/01/2021.
//

#include "../include/readFromSrv.h"
#include <iostream>
#include <thread>
#include <fstream>
#include "../include/connectionHandler.h"


using namespace std;

using std::cin;



    const string host;//ip
    const short port=0;

    readFromSrv::readFromSrv(string host, short port):  host(host), port(port){}

    void readFromSrv::run() {
        ConnectionHandler connectionHandler(host, port);
        if (!connectionHandler.connect()) {
            std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        }

        char bytes [2];//for the opCODE - BYTESTOSHORT
        connectionHandler.getBytes(bytes,2 );
        short opCode = connectionHandler.bytesToShort(bytes);
        char bytesOp [2];
        short msgOp = connectionHandler.getBytes(bytesOp,2);

        if(opCode==12){
            string str = "";
            connectionHandler.getFrameAscii(str, '/0');
            if(str == ""){
                cout << "ACK" + msgOp <<endl;
            }else{
                cout << "ACK" + msgOp + '\n' + str <<endl;
            }
        }
        else if(opCode==13){
            cout << "ERROR " + msgOp << endl;
        }

    }
