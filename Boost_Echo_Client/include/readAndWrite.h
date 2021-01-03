//
// Created by spl211 on 02/01/2021.
//

#ifndef ASS32_READANDWRITE_H
#define ASS32_READANDWRITE_H
#include <string>
#endif //ASS32_READANDWRITE_H
#include <boost/asio.hpp>
using boost::asio::ip::tcp;

#include <thread>
using namespace std;


class readAndWrite{
private:
    string input;
    const string host;//ip
    const short port;
    tcp::socket socket;

public:
    readAndWrite(string input, string host, short port, tcp::socket socket);
    virtual ~readAndWrite();

    void run();

};
