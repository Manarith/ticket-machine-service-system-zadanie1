#include "../include/Server.hpp"
#include <iostream>

int main() {
    Server server;
    std::string session = "abc123";

    server.selectTicket(session, 1);

    std::string name = "Jan Kowalski";
    server.pay(session, 5.0, name);

    return 0;
}