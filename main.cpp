#include <iostream>

 void shortToBytes(short num, char* bytesArr)
{
    bytesArr[0] = ((num >> 8) & 0xFF);
    bytesArr[1] = (num & 0xFF);
}

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

    ConnectionHandler connectionHandler(host,port);
    if(!connectionHandler.connect()){
    std::cerr<< "Cannot connect to" << host<< ":" << port << std::endl;
    return 1;
    }

     char [] bytesArr;
    else{
        shortToBytes
        connectionHandler.sendBytes(bytesArr);
    }


}
