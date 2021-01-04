#include <stdlib.h>
#include "../include/readAndWrite.h"
#include "../include/readFromSrv.h"

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

    readFromSrv readFromSrv(host, port);
    std::thread th2(&readFromSrv::run, &readFromSrv);
    th2.join();

    return 0;
}
