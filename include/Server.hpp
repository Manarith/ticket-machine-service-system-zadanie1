#ifndef SERVER_HPP
#define SERVER_HPP

#include "TicketService.hpp"
#include "CashRegister.hpp"
#include "SessionManager.hpp"

class Server {
    TicketService tickets;
    CashRegister cash;
    SessionManager sessions;

public:
    bool selectTicket(const std::string& session, int id);
    bool cancel(const std::string& session);
    bool pay(const std::string& session, double money, std::string user);
};

#endif