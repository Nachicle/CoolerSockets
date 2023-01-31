#include <CoolerSockets.hpp>

int main(int argc, char const *argv[]) {
    cs::Socket server(cs::Family::IPv4, cs::Protocol::TCP);
    server.bind("0.0.0.0", 3131);
    server.listen(10);
    cs::Socket client = server.accept();
    
    char buffer[512];    
    while(client.receive(buffer, 512) > 0) {
        std::cout << buffer << std::endl;
        client.send(buffer, strlen(buffer));
    }

    return 0;
}