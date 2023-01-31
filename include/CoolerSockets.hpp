#pragma once

#include <iostream>

namespace cs {

    enum class Family {
        IPv4,
        IPv6
    };

    enum class Protocol {
        TCP,
        UDP
    };

    enum class ReturnCode {
        OK,
        ERROR,
        TIMEOUT
    };

    class Socket {

        public:
            Socket(cs::Family, cs::Protocol);
            cs::ReturnCode bind(std::string address, int port);
            cs::ReturnCode listen(int queueSize);
            cs::Socket accept(void);
            cs::ReturnCode connect(std::string address, int port);
            cs::ReturnCode close(void);
            int send(void* buffer, int nbytes);
            cs::ReturnCode sendAll(void* buffer, int nbytes);
            int receive(void* buffer, int nbytes);
            cs::ReturnCode receiveAll(void* buffer, int nbytes);
            
        private:
            Socket(void);
            void* socket = NULL;

    };

}

