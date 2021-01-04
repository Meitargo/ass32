//
// Created by spl211 on 04/01/2021.
//

#ifndef ASS32_READFROMSRV_H
#define ASS32_READFROMSRV_H

#endif //ASS32_READFROMSRV_H
#include <string>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;

#include <thread>
using namespace std;


class readFromSrv{
private:
    const string host;//ip
    const short port;

public:
    readFromSrv(string host, short port);
    virtual ~readFromSrv();

    void run();

};
