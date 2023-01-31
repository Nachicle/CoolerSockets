#include <CoolerSockets.hpp>
#include <map>

#include <CoolSockets.h>

std::map<cs::Family, CSFamily> coolerFamilyToCool {
    {cs::Family::IPv4, CS_FAMILY_IPv4},
    {cs::Family::IPv6, CS_FAMILY_IPv6}
};
std::map<cs::Protocol, CSProtocol> coolerProtocolToCool {
    {cs::Protocol::TCP, CS_PROTOCOL_TCP},
    {cs::Protocol::UDP, CS_PROTOCOL_UDP}
};
std::map<CSReturnCode, cs::ReturnCode> coolReturnCodeToCooler {
    {CS_RETURN_OK, cs::ReturnCode::OK},
    {CS_RETURN_ERROR, cs::ReturnCode::ERROR},
    {CS_RETURN_TIMEOUT, cs::ReturnCode::TIMEOUT}
};

cs::Socket::Socket(void) {
    this->socket = malloc(sizeof(CoolSocket));
}
cs::Socket::Socket(cs::Family family, cs::Protocol protocol) : Socket() {
    CS_NewSocket((CoolSocket*) this->socket, coolerFamilyToCool[family], coolerProtocolToCool[protocol]);
}

cs::ReturnCode cs::Socket::bind(std::string address, int port) {
    return coolReturnCodeToCooler[CS_Bind((CoolSocket*) this->socket, &address[0], port)];
}
cs::ReturnCode cs::Socket::listen(int queueSize) {
    return coolReturnCodeToCooler[CS_Listen(*((CoolSocket*) this->socket), queueSize)];
}
cs::Socket cs::Socket::accept(void) {
    cs::Socket incomingSocket;
    CS_Accept(*((CoolSocket*) this->socket), (CoolSocket*) incomingSocket.socket);
    return incomingSocket;
}
cs::ReturnCode cs::Socket::connect(std::string address, int port) {
    return coolReturnCodeToCooler[CS_Connect(*((CoolSocket*) this->socket), &address[0], port)];
}
cs::ReturnCode cs::Socket::close(void) {
    return coolReturnCodeToCooler[CS_Close(*((CoolSocket*) this->socket))];
}

int cs::Socket::send(void* buffer, int nbytes) {
    return CS_Send(*((CoolSocket*) this->socket), buffer, nbytes);
}
cs::ReturnCode cs::Socket::sendAll(void* buffer, int nbytes) {
    return coolReturnCodeToCooler[CS_SendAll(*((CoolSocket*) this->socket), buffer, nbytes)];
}
int cs::Socket::receive(void* buffer, int nbytes) {
    return CS_Receive(*((CoolSocket*) this->socket), buffer, nbytes);
}
cs::ReturnCode cs::Socket::receiveAll(void* buffer, int nbytes) {
    return coolReturnCodeToCooler[CS_ReceiveAll(*((CoolSocket*) this->socket), buffer, nbytes)];
}
