#include <stdlib.h>
#include "../include/connectionHandler.h"
#include "../include/readAndWrite.h"

#include <iostream>


/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);

    readAndWrite readKey(host, port);
    std::thread th(&readAndWrite::run, &readKey);
    th.join();

    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }

    //TODO: executeThread1

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

    return 0;
}
