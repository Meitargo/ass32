#include <iostream>


int main(int argc, char **argv) {

    if(argc!=2){
       return 1;
    }

    std::string host = argv[0];
    short port = atoi(argv[1]);

    try(Socket sock = new Socket(args[0],Integer.valueOf(args[1])))
    {
        BufferedReader in = new BufferReader(new InputStreamReader(sock.getInputStream()));
        BufferedWriter out = new BufferesWrite(new OutputStreamWriter(sock.getOutputStream()));
    }




}
